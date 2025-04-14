#include "modes_baryton.hpp"

void BarytonModeInit::entering()
{
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();
    // Write the Default Value
    if (read_param(VERSION) == 0)
    {
        write_param(DIAG_CHARGE_DURATION, DEFAULT_DIAG_CHARGE_DURATION);
        write_param(DIAG_DISCHARGE_DURATION, DEFAULT_DIAG_DISCHARGE_DURATION);
        write_param(BAT_1_Disable, DEFAULT_BAT_1_Disable);
        write_param(BAT_1_Max, DEFAULT_BAT_1_Max);
        write_param(BAT_1_Min, DEFAULT_BAT_1_Min);
        write_param(BAT_2_Disable, DEFAULT_BAT_2_Disable);
        write_param(BAT_2_Max, DEFAULT_BAT_2_Max);
        write_param(BAT_2_Min, DEFAULT_BAT_2_Min);
    }
    write_param(VERSION, 23);
}
void BarytonModeInit::routine()
{
    // Read and update the parameter of the BMS
}
void BarytonModeInit::leaving(int nextMode)
{
}
void BarytonModeInit::shootHK()
{
    write_HK(read_param(BAT1_VOLTAGE), 2);
    write_HK(read_param(BAT2_VOLTAGE), 3);
    write_HK(read_param(BAT1_TEMP), 4);
    write_HK(read_param(BAT2_TEMP), 5);
}