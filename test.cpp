#include <iostream>
using namespace std;
#include "check.h"
#include "combat.h"
#include <cstdio>

int main()
{
    srand(time(NULL));
    monster A("test",100,10,10,20,5);
    monster B("yeah",100,10,10,20,5);
    A.upgrade();
    A.battle(A,B);
}
