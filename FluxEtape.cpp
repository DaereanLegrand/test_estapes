#include "mode.hpp"
#include "Etape.hpp"
#include "FluxEtape.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

FluxEtape::FluxEtape(int size) : size(size) {
    currentEtape = 0;
    lastTime = 0;

    etapes = (Etape **)malloc(size * sizeof(Etape *));
}

Etape*
FluxEtape::operator[] (int n)
{
    return etapes[n];
}

int  
FluxEtape::getEtape()
{
    return currentEtape;
}

void
FluxEtape::goNextEtape(int nextEtapeId)
{
    currentEtape = nextEtapeId;
}

void
FluxEtape::run()
{
    if (currentEtape < size) {
        printf("currentEtape: %d \n", currentEtape);
        lastTime = clock();
        etapes[currentEtape]->run();
        lastTime = clock() - lastTime;
        goNextEtape(etapes[currentEtape]->nextEtapeId);
        printf("etape a pris %d\n", lastTime);
    }
}
