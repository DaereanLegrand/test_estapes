#ifndef ETAPEDEF
#define ETAPEDEF

#include "LibSpikCU_slave.h"
#include "CU_BARYTON_Reg.h"

class Etape
{
protected:
    int etapeId;

    using Action = void(*)();

    Action enteringAction;
    Action routineAction;
    Action leavingAction;

    int entering();
    int routine();
    int leaving();

public:
    Etape(int etapeId, Action entering, Action routine, Action leaving) : etapeId(etapeId), enteringAction(entering), routineAction(routine), leavingAction(leaving) {}

    Etape* next;
    int run();
    virtual void shootHK();
};

#endif
