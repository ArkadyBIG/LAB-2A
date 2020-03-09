#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <random>
#include <ctime>

#include "MAIN_HEAD.h"
#include "Circle.h"

using namespace std;
const int arry_size=100000,
        number_iteration=1000;

template <typename T>
void _search(T any_arry)
{

    int i=0;
    for(i=0;i<arry_size;++i){//nu++;
        if(any_arry[i].Radius==1001)
            break;}


}
template <typename T>
void Test_ARRY(T any_arry,int iterations=number_iteration)
{
    clock_t Time=clock();
    for(int i=0;i<iterations;++i){
    any_arry[rand()%arry_size].Radius=1001;
    _search(any_arry);
    }
    cout<<arry_size<<"     "<<sizeof(any_arry)*arry_size<<"             "<<clock()-Time<<endl;

}

void BENCHMARK()
{
    srand(time(0));
    system("cls");
    cout<<"BENCHMARK MODE             <Press ESC any time to go back to main menu>\nTEST  FOR "<<number_iteration<<" ITERATIONS\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<"Type--------Size----|--"<<"Memory(bytes)--|---Time(miliSec)----"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    ////////////VECTOR TEST
    {
        vector<Circle> TEST(arry_size);
        cout<<"VECTOR:     ";
        Test_ARRY(TEST);
    }
    ////////////////MY LIST TEST
    {
        circled_list<Circle> TEST(arry_size);
        cout<<"My list:    ";
        Test_ARRY(TEST);
    }
    //////////FIXED SIZE ARRY TEST
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"FOR "<<number_iteration*number_iteration<<" ITERATIONS"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        Circle TEST[arry_size];
        cout<<"Fixed arry: ";
        Test_ARRY(TEST,number_iteration*number_iteration);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    _getch();
}
