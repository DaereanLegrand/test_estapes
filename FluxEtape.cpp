#include "mode.hpp"
#include "Etape.hpp"
#include "FluxEtape.hpp"
#include <cstdio>
#include <cstdlib>

FluxEtape::FluxEtape(int size) : size(size) {
    currentEtape = 0;

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
        etapes[currentEtape]->run();
        goNextEtape(etapes[currentEtape]->nextEtapeId);
        printf("\n");
    }
}
