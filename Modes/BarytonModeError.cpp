#include "modes_baryton.hpp"

void BarytonModeError::entering()
{
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();
}
void BarytonModeError::routine()
{
    // Nothing to do
}
void BarytonModeError::leaving(int nextMode)
{
}

void BarytonModeError::shootHK()
{
    write_HK(read_param(BAT1_VOLTAGE), 2);
    write_HK(read_param(BAT2_VOLTAGE), 3);
    write_HK(read_param(BAT1_TEMP), 4);
    write_HK(read_param(BAT2_TEMP), 5);
}
