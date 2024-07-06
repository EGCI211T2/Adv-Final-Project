#include <iostream>
using namespace std;
#include "check.h"
#include "combat.h"
#include <cstdio>

int main()
{
    char*x;
    x=new char[20];
    cout<<"Enter monster name ";
    cin>>x;
    srand(time(NULL));
    monster A(x,20,1,1,5,1);
    monster B("Purikuuu",30,2,2,10,2);
    A.upgrade();
    A.battle(A,B);
}
