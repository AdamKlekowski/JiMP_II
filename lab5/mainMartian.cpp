#include<iostream>
using ::std::cout;
using ::std::endl;

#include<vector>
using ::std::vector;

#ifdef __linux__ 
    #include<unistd.h>
#elif _WIN32
    #include<windows.h>
#else
    #error "OS not supported!"
#endif

#include "Martian.h"

int main()
{
    srand(time(NULL));
    vector<Martian*> martians;

    short decision;
    int numbers;
    while(1)
    {
        decision = rand()%2; // 0->delete objects, 1->add objects
        numbers = rand()%3 + 1; // how many objects add/delete
        if(decision==0)
        {
            for (int i=0; i<numbers; i++)
            {
                Martian *newMartian = new Martian();
                martians.push_back(newMartian);
            }
        }
        else
        {
            if (numbers>Martian::martianCount) numbers=Martian::martianCount;
            for (int i=0; i<numbers; i++)
            {
                delete martians.back();
                martians.pop_back();
            }
        }
        
        cout << "martianCount: " << Martian::martianCount << endl;
        for (auto soldier : martians)
        {
            soldier->Attack();
        }

        #ifdef __linux__ 
            sleep(1);
            system("clear");
        #elif _WIN32
            sleep(1000);
            system("clr");
        #else
            #error "OS not supported!"
        #endif
    }
}