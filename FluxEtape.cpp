#include "FluxEtape.hpp"
#include <cstddef>
#include <cstdio>

FluxEtape::FluxEtape() {
    size = 0;
    currentEtape = 0;
    isNextEtape = false;

    root = NULL;
    current = NULL;
}

Etape*
FluxEtape::operator[] (int n)
{
    Etape* it = root;
    for (int i = 0; it != NULL && i < n; i++)
        it = it->next;

    return it;
}

int  
FluxEtape::getEtape()
{
    return currentEtape;
}

int 
FluxEtape::nextEtape()
{
    if (isNextEtape == false)
        return 0;

    if (current->next == NULL) {
        currentEtape += 1;
        return -1;
    }

    current = current->next;
    currentEtape += 1;

    return 1;
}

int
FluxEtape::addEtape(Etape* e)
{
    if (root == NULL) {
        root = e;
        size = 1;
        return 1;
    }

    Etape* last = (*this)[size - 1];
    last->next = e;
    last = last->next;
    size += 1;
    return 1;
}

void
FluxEtape::run()
{
    if (current == NULL && size > 0) {
        current = root;
        currentEtape = 0;
    }

    while (currentEtape < size) {
        printf("currentEtape: %d \t", currentEtape);
        current->run();
        isNextEtape = true;
        nextEtape();
        printf("\n");
    }
}

void 
FluxEtape::removeEtape (Etape* e)
{
    // NOT NECESSARY
}
