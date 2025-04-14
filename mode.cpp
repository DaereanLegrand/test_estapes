#include "mode.hpp"
#include "LibSpikCU_slave.h"
#include "CU_BARYTON_Reg.h"
#include <cstdio>
#include <unistd.h>

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
    this->currentMode = 2;
    this->nextMode = 2;
}

void ModeStateManager::run()
{
    while (1)
    {
        printf("run... currentMode: %d\n", currentMode);;
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
    printf("nextMode: %d and currentMode: %d\n", nextMode, currentMode);
    sleep(1);
    if (nextMode != currentMode)
    {
        write_param(MODE_SUIVANT, nextMode);
        return true;
    }
    // Check if the OBC has changed the mode
    //nextMode = read_param(MODE_SUIVANT);
    return nextMode != currentMode;
}

void ModeStateManager::shootHK()
{
    modes[currentMode]->shootHK();
}
