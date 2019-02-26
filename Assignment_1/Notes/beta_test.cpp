#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <iomanip>
using namespace std;
#include "beta.h"

int main()
{
    default_random_engine* gptr;
    gptr = new default_random_engine (time(NULL));
    /*
    beta Btest(3);
    for(int i=0; i<10; i++)
    {
        Btest.addVal(gptr);
    }

    Btest.display();
    */
    list<beta>AllBeta;
    list<beta>::iterator Bitr;

    beta * bptr;
    int r1, r2;
    uniform_int_distribution<int> Numbeta(4,10);
    uniform_int_distribution<int> keyVal(1,10);
    uniform_int_distribution<int> NumVal(0,20);
    r1=Numbeta(*gptr);
    for(int i=0; i<r1; i++)
    {
        r2=keyVal(*gptr);
        bptr = new beta(r2);
        AllBeta.push_back(*bptr);

    }

    Bitr=AllBeta.begin();

    while(Bitr!=AllBeta.end())
    {
        r1=NumVal(*gptr);
        cout<<"trying to add"<<setw(4)<<r1<<" values to Beta"<<endl;
        for(int i=0; i<r1; i++)
        {
            Bitr->addVal(gptr);
        }
        Bitr++;
    }
///------------------------------
    Bitr=AllBeta.begin();
    while(Bitr!=AllBeta.end())
    {   Bitr->init();
        Bitr->display();
        Bitr++;
    }
    int target;
    cout<<endl<<endl;
    cout<<"Search all Beta for what value?"<<endl;
    cin>>target;
    Bitr=AllBeta.begin();
    while(Bitr!=AllBeta.end())
    {
        Bitr->findval(target);
        Bitr++;
    }


    return 0;
}
