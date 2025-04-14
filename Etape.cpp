#include "Etape.hpp"

void
Etape::entering() 
{

}

void
Etape::routine() 
{

}

void
Etape::leaving() 
{

}

void
Etape::run()
{
    entering();
    routine();
    leaving();
}

void Etape::shootHK()
{
    write_HK(read_param(CTRL_uC), 0);
    write_HK(read_param(MODE), 1);
    write_HK(read_param(TIME_CCSDS_100MS), 4);
}
