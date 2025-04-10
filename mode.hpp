#ifndef MODEDEF
#define MODEDEF

#include "FluxEtape.hpp"

class Mode
{
protected:
    int modeId;

public:
    Mode(int modeId) : modeId(modeId) {}
    FluxEtape flux;
    virtual void entering();
    virtual void routine();
    virtual void leaving(int nextMode);
    virtual void shootHK();
};

class ModeStateManager
{
private:
    Mode **modes;
    int currentMode = 0;
    int modeCount;
    int nextMode;

public:
    ModeStateManager(Mode **modes, int modeCount);
    void run();
    bool hasModeChanged();
    void shootHK();
};
;

#endif
