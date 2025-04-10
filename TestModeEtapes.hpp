#include "Etape.hpp"

class _001 : public Etape {
protected:
    int id;

public:
    void entering();
    void routine();
    void leaving();

    _001(int etapeId) : Etape(etapeId), id(etapeId) {  }
};


class _002 : public Etape {
protected:
    int id;

public:
    void entering();
    void routine();
    void leaving();

    _002(int etapeId) : Etape(etapeId), id(etapeId) {  }
};
