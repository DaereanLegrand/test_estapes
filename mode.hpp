#ifndef MODEDEF
#define MODEDEF

class FluxEtape;

class Mode
{
protected:
    int modeId;
    FluxEtape* flux;

public:
    Mode(int modeId) : modeId(modeId) {}
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

#endif
