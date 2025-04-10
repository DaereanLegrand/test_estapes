#include "Etape.hpp"

int 
Etape::entering() 
{
    if (enteringAction) {
        enteringAction(); 
        return 1;
    } else {
        return 0;
    }
}

int 
Etape::routine() 
{
    if (routineAction) {
        routineAction();
        return 1;
    } else {
        return 0;
    }
}

int 
Etape::leaving() 
{
    if (leavingAction) {
        leavingAction();
        return 1;
    } else {
        return 0;
    } 
}

int
Etape::run()
{
    entering();
    routine();
    leaving();
    return 1;
}

void Etape::shootHK()
{
    write_HK(read_param(CTRL_uC), 0);
    write_HK(read_param(MODE), 1);
    write_HK(read_param(TIME_CCSDS_100MS), 4);
}
