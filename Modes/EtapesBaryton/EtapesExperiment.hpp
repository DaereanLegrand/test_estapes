#include "../../Etape.hpp"
#include "../modes_baryton.hpp"

class BarytonExperimentEtapes : public Etape {
protected:
    BarytonModeExperiment* mode;
public:
    virtual void entering() override;
    virtual void routine() override;
    virtual void leaving() override;
    BarytonExperimentEtapes(int etapeId, int nextEtapeId, BarytonModeExperiment* mode) : Etape(etapeId, nextEtapeId), mode(mode) {  }
};

class _001 : public BarytonExperimentEtapes {
protected:
    int id;

public:
    void entering() override;
    void routine() override;
    void leaving() override;

    _001(int etapeId, int nextEtapeId, BarytonModeExperiment* mode) : BarytonExperimentEtapes(etapeId, nextEtapeId, mode), id(etapeId) {  }
};


class _002 : public BarytonExperimentEtapes {
protected:
    int id;

public:
    void entering() override;
    void routine() override;
    void leaving() override;

    _002(int etapeId, int nextEtapeId, BarytonModeExperiment* mode) : BarytonExperimentEtapes(etapeId, nextEtapeId, mode), id(etapeId) {  }
};

class _003 : public BarytonExperimentEtapes {
protected:
    int id;

public:
    void entering() override;
    void routine() override;
    void leaving() override;

    _003(int etapeId, int nextEtapeId, BarytonModeExperiment* mode) : BarytonExperimentEtapes(etapeId, nextEtapeId, mode), id(etapeId) {  }
};
