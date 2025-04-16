#ifndef FLUXETAPE
#define FLUXETAPE

class Mode;
class Etape;

class FluxEtape 
{
protected:
    const int size;
    int currentEtape;
    int nextEtape;
    int lastTime;

public:
    Etape** etapes;
    Etape* operator[] (int);
    FluxEtape(int);

    int getEtape();
    void goNextEtape(int);
    void run();
};

#endif
