#include "modes_baryton.hpp"
#include "../FluxEtape.hpp"
#include "EtapesBaryton/EtapesExperiment.hpp"
#include <cstdio>

BarytonModeExperiment::BarytonModeExperiment() : BarytonMode(0x2000) 
{
    flux = new FluxEtape(3);
    flux->etapes[0] = new _001(1, 1, this);
    flux->etapes[1] = new _002(2, 2, this);
    flux->etapes[2] = new _003(3, 3, this);
};

void BarytonModeExperiment::entering()
{
    printf("Mode Experiment: entering...\n");
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();

    bms.batteries[0]->enabled = !read_param(BAT_1_Disable);
    bms.batteries[1]->enabled = !read_param(BAT_2_Disable);

    bms.batteries[0]->vMax = read_param(BAT_1_Max);
    bms.batteries[0]->vMin = read_param(BAT_1_Min);
    bms.batteries[1]->vMax = read_param(BAT_2_Max);
    bms.batteries[1]->vMin = read_param(BAT_2_Min);

    currentBattery = 0;
    state = STANDBY;
    prevState = STANDBY;

    lastTimeStamp = 0;
    count = 0;
}

void BarytonModeExperiment::routine()
{
    printf("Mode Experiment: routine...\n");
    flux->run();
    /*
    lastTimeStamp++;
    if (lastTimeStamp > 1000)
    {
        lastTimeStamp = 0;
    }

    // // End Conditions
    switch (state)
    {
    case CHARGE:
        if (bms.batteries[currentBattery]->getVoltage() > bms.batteries[currentBattery]->vMax)
        {
            bms.batteries[currentBattery]->standby();
            state = STANDBY;
        }
        break;
    case DISCHARGE:
        if (bms.batteries[currentBattery]->getVoltage() < bms.batteries[currentBattery]->vMin)
        {
            bms.batteries[currentBattery]->standby();
            state = CHARGE;
        }
        break;
    case STANDBY:
        currentBattery = (currentBattery + 1) % 2;
        count++;
        state = DISCHARGE;
        break;
    default:
        break;
    }

    if (lastTimeStamp % 100 == 0)
    {
        // // Entering the state
        if (prevState != state)
        {
            switch (state)
            {
            case CHARGE:
                bms.batteries[currentBattery]->charge();
                break;
            case DISCHARGE:
                bms.batteries[currentBattery]->discharge();
                break;
            case STANDBY:
                bms.batteries[currentBattery]->standby();
                break;
            default:
                break;
            }
            prevState = state;
        }

        write_param(ChargeCurrent, (state == CHARGE) ? bms.getChargeCurrent() : 0);
        write_param(DischargeCurrent, (state == DISCHARGE) ? bms.getDischargeCurrent() : 0);

        write_param(BAT1_STATE, bms.batteries[0]->state);
        write_param(BAT1_VOLTAGE, bms.batteries[0]->getVoltage());
        write_param(BAT1_TEMP, bms.batteries[0]->getTemperature());
        write_param(BAT1_CYCLE, bms.batteries[0]->nbCycle);

        write_param(BAT2_STATE, bms.batteries[1]->state);
        write_param(BAT2_VOLTAGE, bms.batteries[1]->getVoltage());
        write_param(BAT2_TEMP, bms.batteries[1]->getTemperature());
        write_param(BAT2_CYCLE, bms.batteries[1]->nbCycle);
    }
    */
}

void BarytonModeExperiment::leaving(int nextMode)
{
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();
}
void BarytonModeExperiment::shootHK()
{
    write_HK(read_param(ChargeCurrent), 0);
    write_HK(read_param(DischargeCurrent), 1);
    write_HK(read_param(BAT1_VOLTAGE), 2);
    write_HK(read_param(BAT2_VOLTAGE), 3);
    write_HK(read_param(BAT1_TEMP), 4);
    write_HK(read_param(BAT2_TEMP), 5);
    write_HK(read_param(BAT1_STATE), 6);
    write_HK(read_param(BAT2_STATE), 7);
}
