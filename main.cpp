#include "mode.hpp"
#include <stdio.h>

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

    void (*enter)() = []() {
        printf("entering...");
    };

    void (*routine)() = []() {
        printf("routine...");
    };

    void (*leave)() = []() {
        printf("leaving...");
    };

    Etape _001(0, enter, routine, leave);

    test.flux.addEtape(&_001);

    test.entering();
    test.routine();
}
