#include "modes_baryton.hpp"

void BarytonMode::entering()
{
    bms.batteries[0]->standby();
    bms.batteries[1]->standby();
}
void BarytonMode::routine()
{
    // Nothing to do
}
void BarytonMode::leaving(int nextMode)
{
}
void BarytonMode::shootHK()
{
    write_HK(read_param(BAT1_VOLTAGE), 2);
    write_HK(read_param(BAT2_VOLTAGE), 3);
    write_HK(read_param(BAT1_TEMP), 4);
    write_HK(read_param(BAT2_TEMP), 5);
}

uint32_t readTime()
{
    return read_param(TIME_CCSDS_MIN) * 60 * 1000 + read_param(TIME_CCSDS_100MS) * 100;
}
