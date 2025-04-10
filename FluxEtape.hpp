#ifndef FLUXETAPE
#define FLUXETAPE

#include "Etape.hpp"

class FluxEtape 
{
protected:
    int size;
    int currentEtape;
    bool isNextEtape;
    Etape* root;
    Etape* current;

public:
    Etape* operator[] (int n);
    FluxEtape();

    int getEtape();
    int nextEtape();

    int addEtape (Etape*);
    void removeEtape (Etape*);

    void run();
};

#endif
