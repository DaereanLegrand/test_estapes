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
