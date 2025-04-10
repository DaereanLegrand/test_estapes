#include "TestModeEtapes.hpp"
#include <cstdio>

void
_001::entering()
{
    printf("entering... %d", id);
    write_HK(1, 0);
}

void
_001::routine()
{

    printf("routine... %d", id);
    write_HK(1, 0);
}

void
_001::leaving()
{
    printf("leaving... %d", id);
    write_HK(1, 0);
}

void
_002::entering()
{
    printf("entering... %d", id);
    write_HK(2, 0);
}

void
_002::routine()
{

    printf("routine... %d", id);
    write_HK(2, 0);
}

void
_002::leaving()
{
    printf("leaving... %d", id);
    write_HK(2, 0);
}
