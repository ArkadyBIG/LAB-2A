#include <iostream>
#include <vector>
#include "MAIN_HEAD.h"
#include "choose_a_choise.h"
#include "Interactive.h"
#include "BENCHMARK.h"
#include "DEMONSTRATION.h"
using namespace std;


int main()
{

    while(1){
         system("cls");
         cout<<"MAIN MENU\n";
        switch(choose({"Interactive","Demonstration","Benchmark","EXIT"}))
        {
        case 0:  //"Interactive"
            INTERACTIVE();
            break;
        case 1:  //"Demonstration"
            DEMONSTRATION();
            break;
        case 2:  //"Benchmark"
            BENCHMARK();
            break;
        case 3:
            return 1;
        }
    }
    return 0;
}
