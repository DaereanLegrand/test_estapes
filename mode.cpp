#include "mode.hpp"

void Mode::entering()
{
    // write_param(MODE, this->modeId);
}

void Mode::leaving(int nextMode)
{
    write_param(MODE, nextMode);
}

void Mode::routine()
{
    // Do nothing
}

void Mode::shootHK()
{
    write_HK(read_param(CTRL_uC), 0);
    write_HK(read_param(MODE), 1);
    write_HK(read_param(TIME_CCSDS_100MS), 4);
}

ModeStateManager::ModeStateManager(Mode **modes, int modeCount)
{
    this->modes = modes;
    this->modeCount = modeCount;
    this->currentMode = 0;
}

void ModeStateManager::run()
{
    while (1)
    {
        write_param(MODE, currentMode);
        modes[currentMode]->entering();
        while (!hasModeChanged())
        {
            modes[currentMode]->routine();
        }
        modes[currentMode]->leaving(nextMode);
        currentMode = nextMode;
    }
}

/**
 * @brief Check if the mode has changed
 * @return true if the mode has changed
 */
bool ModeStateManager::hasModeChanged()
{
    // Two Possible ways of changing mode either by reading the
    // nextMode from the OBC or by checking the currentMode

    // The Payload has changed the mode (i.e END or ERROR )
    if (nextMode != currentMode)
    {
        write_param(MODE_SUIVANT, nextMode);
        return true;
    }
    // Check if the OBC has changed the mode
    nextMode = read_param(MODE_SUIVANT);
    return nextMode != currentMode;
}

void ModeStateManager::shootHK()
{
    modes[currentMode]->shootHK();
}
