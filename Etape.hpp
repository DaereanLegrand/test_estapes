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
    int nextEtapeId;
    Etape(int etapeId, int nextEtapeId) : etapeId(etapeId), nextEtapeId(nextEtapeId) {}

    void run();
    virtual void shootHK();
};

#endif
