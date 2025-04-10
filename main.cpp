#include "mode.hpp"
#include "TestModeEtapes.hpp"

class TestMode: public Mode {

public:
    TestMode(int mode) : Mode(mode) {  };

    void 
    entering() override
    {

    }

    void 
    routine() override
    {
        flux.run();
    }

    void 
    leaving(int nextMode) override
    {

    }

    void 
    shootHK() override 
    {
        Mode::shootHK();
    }
};

int
main()
{
    TestMode test(0);
    _001 __001(1);
    _002 __002(2);

    test.flux.addEtape(&__001);
    test.flux.addEtape(&__002);

    test.entering();
    test.routine();
}
