#ifndef ETAPEDEF
#define ETAPEDEF

#include "LibSpikCU_slave.h"
#include "CU_BARYTON_Reg.h"

class Etape
{
protected:
    int etapeId;

    virtual void entering();
    virtual void routine();
    virtual void leaving();

public:
    Etape(int etapeId) {}

    Etape* next;
    int run();
    virtual void shootHK();
};

#endif
