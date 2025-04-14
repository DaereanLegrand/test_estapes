#include <cstdio>
#include <stdint.h>
#include <stdlib.h>

#include "mode.hpp"
#include "Modes/modes_baryton.hpp"

BarytonModeInit barytonModeInit;   
BarytonModeDiagnostic barytonModeDiagnostic;
BarytonModeExperiment barytonModeExperiment;
BarytonModeError barytonModeError;
BarytonModeEnd barytonModeEnd;

Mode *modes[5] = {&barytonModeInit
    , &barytonModeDiagnostic
    , &barytonModeExperiment
    , &barytonModeError
    , &barytonModeEnd};

ModeStateManager barytonStateManager(modes, 5);

int main(void)
{
    int count = 0;

    while (1)
    {
        barytonStateManager.run();
    }
    return 0;
  
}

void shotHK(void)
{
    barytonStateManager.shootHK();
}
