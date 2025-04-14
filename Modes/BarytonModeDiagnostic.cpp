#include "modes_baryton.hpp"

void BarytonModeDiagnostic::entering()
{
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();

    currentBattery = 0;
    lastTimeStamp = readTime();
    lastTimeStampParam = readTime();

    chargeCycleLength = read_param(DIAG_CHARGE_DURATION);
    dischargeCycleLength = read_param(DIAG_DISCHARGE_DURATION);

    bms.batteries[0]->enabled = !read_param(BAT_1_Disable);
    bms.batteries[1]->enabled = !read_param(BAT_2_Disable);

    bms.batteries[0]->vMax = read_param(BAT_1_Max);
    bms.batteries[0]->vMin = read_param(BAT_1_Min);
    bms.batteries[1]->vMax = read_param(BAT_2_Max);
    bms.batteries[1]->vMin = read_param(BAT_2_Min);

    bms.batteries[0]->nbCycle = 0;
    bms.batteries[1]->nbCycle = 0;
}
#define COUNT TEST14
void BarytonModeDiagnostic::routine()
{
    uint32_t elapsedTime = readTime() - lastTimeStamp;
    uint32_t elapsedTimeParam = readTime() - lastTimeStampParam;

    // Check if the time has passed
    if (elapsedTime > chargeCycleLength)
    {

        // Power off (standby) the batteries
        bms.batteries[0]->standby();
        bms.batteries[1]->standby();

        if (bms.batteries[currentBattery]->enabled && bms.batteries[currentBattery]->voltage > bms.batteries[currentBattery]->vMin)
            bms.batteries[currentBattery]->discharge();

        // Switch to the other battery
        currentBattery = (currentBattery + 1) % 2;

        if (bms.batteries[currentBattery]->enabled && bms.batteries[currentBattery]->voltage < bms.batteries[currentBattery]->vMax)
            bms.batteries[currentBattery]->charge();

        bms.batteries[currentBattery]->nbCycle++;

        lastTimeStamp = readTime();
        elapsedTime = 0;
    }

    // Never discharge for more than 100 cycles
    if (elapsedTime > dischargeCycleLength)
    {
        bms.batteries[(currentBattery + 1) % 2]->standby();
    }

    if (elapsedTimeParam > 100)
    {
        write_param(EMPTY_2, readTime());
        write_param(EMPTY_4, elapsedTime);
        lastTimeStampParam = readTime();
        write_param(ChargeCurrent, (bms.batteries[currentBattery]->state == CHARGE) ? bms.getChargeCurrent() : 0);
        write_param(DischargeCurrent, (bms.batteries[(currentBattery + 1) % 2]->state == DISCHARGE) ? bms.getDischargeCurrent() : 0);

        write_param(BAT1_STATE, bms.batteries[0]->state);
        write_param(BAT1_VOLTAGE, bms.batteries[0]->getVoltage());
        write_param(BAT1_TEMP, bms.batteries[0]->getTemperature());
        write_param(BAT1_CYCLE, bms.batteries[0]->nbCycle);

        write_param(BAT2_STATE, bms.batteries[1]->state);
        write_param(BAT2_VOLTAGE, bms.batteries[1]->getVoltage());
        write_param(BAT2_TEMP, bms.batteries[1]->getTemperature());
        write_param(BAT2_CYCLE, bms.batteries[1]->nbCycle);

        // Safe state
        if (bms.batteries[0]->voltage > bms.batteries[0]->vMax && bms.batteries[0]->state == CHARGE)
            bms.batteries[0]->standby();
        if (bms.batteries[1]->voltage > bms.batteries[1]->vMax && bms.batteries[1]->state == CHARGE)
            bms.batteries[1]->standby();
        if (bms.batteries[0]->voltage < bms.batteries[0]->vMin && bms.batteries[0]->state == DISCHARGE)
            bms.batteries[0]->standby();
        if (bms.batteries[1]->voltage < bms.batteries[1]->vMin && bms.batteries[0]->state == DISCHARGE)
            bms.batteries[1]->standby();
    }

}
void BarytonModeDiagnostic::leaving(int nextMode)
{
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();
}
void BarytonModeDiagnostic::shootHK()
{
    write_HK(read_param(ChargeCurrent), 0);
    write_HK(read_param(DischargeCurrent), 1);
    write_HK(read_param(BAT1_VOLTAGE), 2);
    write_HK(read_param(BAT2_VOLTAGE), 3);
    write_HK(read_param(BAT1_TEMP), 4);
    write_HK(read_param(BAT2_TEMP), 5);
}
