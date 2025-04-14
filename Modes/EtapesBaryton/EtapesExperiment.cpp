#include "EtapesExperiment.hpp"
#include "../driver_bat.h"
#include <cstdio>

void
BarytonExperimentEtapes::entering()
{

}

void
BarytonExperimentEtapes::routine()
{

}

void
BarytonExperimentEtapes::leaving()
{

}

void
_001::entering()
{
    printf("\tentering... %d\n", id);
}

void
_001::routine()
{
    printf("\troutine... %d\n", id);
    mode->lastTimeStamp++;
    if (mode->lastTimeStamp > 1000)
    {
        mode->lastTimeStamp = 0;
    }
}

void
_001::leaving()
{
    printf("\tleaving... %d\n", id);
}

void
_002::entering()
{
    printf("\tentering... %d\n", id);
}

void
_002::routine()
{
    printf("\troutine... %d\n", id);

    // // End Conditions
    switch (mode->state)
    {
    case CHARGE:
        if (bms.batteries[mode->currentBattery]->getVoltage() > bms.batteries[mode->currentBattery]->vMax)
        {
            bms.batteries[mode->currentBattery]->standby();
            mode->state = STANDBY;
        }
        break;
    case DISCHARGE:
        if (bms.batteries[mode->currentBattery]->getVoltage() < bms.batteries[mode->currentBattery]->vMin)
        {
            bms.batteries[mode->currentBattery]->standby();
            mode->state = CHARGE;
        }
        break;
    case STANDBY:
        mode->currentBattery = (mode->currentBattery + 1) % 2;
        mode->count++;
        mode->state = DISCHARGE;
        break;
    default:
        break;
    }

}

void
_002::leaving()
{
    printf("\tleaving... %d\n", id);
}

void
_003::entering()
{
    printf("\tentering... %d\n", id);
}

void
_003::routine()
{
    printf("\troutine... %d\n", id);

    // // End Conditions
    if (mode->lastTimeStamp % 100 == 0)
    {
        // // Entering the state
        if (mode->prevState != mode->state)
        {
            switch (mode->state)
            {
            case CHARGE:
                bms.batteries[mode->currentBattery]->charge();
                break;
            case DISCHARGE:
                bms.batteries[mode->currentBattery]->discharge();
                break;
            case STANDBY:
                bms.batteries[mode->currentBattery]->standby();
                break;
            default:
                break;
            }
            mode->prevState = mode->state;
        }

        write_param(ChargeCurrent, (mode->state == CHARGE) ? bms.getChargeCurrent() : 0);
        write_param(DischargeCurrent, (mode->state == DISCHARGE) ? bms.getDischargeCurrent() : 0);

        write_param(BAT1_STATE, bms.batteries[0]->state);
        write_param(BAT1_VOLTAGE, bms.batteries[0]->getVoltage());
        write_param(BAT1_TEMP, bms.batteries[0]->getTemperature());
        write_param(BAT1_CYCLE, bms.batteries[0]->nbCycle);

        write_param(BAT2_STATE, bms.batteries[1]->state);
        write_param(BAT2_VOLTAGE, bms.batteries[1]->getVoltage());
        write_param(BAT2_TEMP, bms.batteries[1]->getTemperature());
        write_param(BAT2_CYCLE, bms.batteries[1]->nbCycle);
    }
}

void
_003::leaving()
{
    printf("\tleaving... %d\n", id);
}
