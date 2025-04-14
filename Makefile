ETAPES=Modes/EtapesBaryton/EtapesExperiment.cpp
DRIVERS=Modes/driver_bat.c Modes/modes_baryton.cpp
MODES=Modes/BarytonModeDiagnostic.cpp Modes/BarytonModeEnd.cpp Modes/BarytonModeError.cpp Modes/BarytonModeExperiment.cpp Modes/BarytonModeInit.cpp
CLASSES=mode.cpp FluxEtape.cpp Etape.cpp

all:
	g++ main.cpp $(CLASSES) $(DRIVERS) $(MODES) $(ETAPES) -o program
