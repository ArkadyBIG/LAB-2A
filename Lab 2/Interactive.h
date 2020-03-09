#ifndef INTERACTIVE_H_INCLUDED
#define INTERACTIVE_H_INCLUDED

using namespace std;
#include "Circle.h"
#include "MAIN_HEAD.h"
#include "choose_a_choise.h"


#include <conio.h>
#include <vector>

circled_list<Circle> mycircles(0);
void Show_circles()
{
    if(mycircles.size()==0)
    {
        cout<<"No circles\n";
        _getch();
        return;
    }
    cout<<(char)252<<"   X   Y   Radius\n";
    for(int i=0;i<mycircles.size();++i)
        cout<<i+1<<"   "<<mycircles[i].X<<"   "<<mycircles[i].Y<<"   "<<mycircles[i].Radius<<endl;
    cout<<"Press any key to continue\n";
    _getch();
}

void Add_circle()
{

    char c;
    int cor_x=INT_MAX,cor_y=INT_MAX,rad=INT_MAX;
    //////////////////////////
    cout<<"Enter X coordinate of the circle             <ESC to go back>\n";
    while(c=_getch()){
    if(c==27)
        return;
    if(c==13 && cor_x!=INT_MAX) break;
    cout<<c;
    if(cor_x==INT_MAX) cor_x=c-48;
    else
        cor_x=cor_x*10+c-48;
    }

    //////////////////////////
    cout<<"\nEnter Y coordinate of the circle             <ESC to go back>\n";
    while(c=_getch()){
    if(c==27)
        return;
    if(c==13 && cor_y!=INT_MAX) break;
    cout<<c;
    if(cor_y==INT_MAX) cor_y=c-48;
    else
        cor_y=cor_y*10+c-48;
    }

    ///////////////////////////
    cout<<"\nEnter RADIUS of the circle             <ESC to go back>\n";
    while(c=_getch()){
    if(c==27)
        return;
    if(c==13 && rad!=INT_MAX) break;
    cout<<c;
    if(rad==INT_MAX) rad=c-48;
    else
        rad=rad*10+c-48;
    }
    Circle C;
    C.Radius=rad;
    C.X=cor_x;
    C.Y=cor_y;
    //mycircles.push_back((Circle) {cor_x,cor_y,rad});
    mycircles.push_back(C);



}
void delete_circle()
{
    if(mycircles.size()==0)
    {
        cout<<"No circles\nPress any key to continue";
        _getch();
        return;
    }
    vector<string> S(0);
    for(int i=0;i<mycircles.size();++i)
    {
        string node_string;
        node_string+= to_string(i+1) +"   "+to_string(mycircles[i].X)+"   "+to_string(mycircles[i].Y)+"   "+to_string(mycircles[i].Radius);
        S.push_back(node_string);
    }
    cout<<"Chose circle to delete\n";
    cout<<(char)252<<"   X   Y   Radius\n";
    int to_delete=choose(S,1);
    if(to_delete==-1)
        return;
    mycircles.remove(to_delete);

}
void INTERACTIVE()
{
    while(1){
            system("cls");
            cout<<"INTERACTIVE MODE\n";

    switch(choose({"Show all circles","Add a circle","Delete circle"},1))
    {
    case 0:
        Show_circles();
        break;
    case 1:
        Add_circle();
        break;
    case 2:
        delete_circle();
        break;
    case -1:
        return;
    }
    }

}
#endif // INTERACTIVE_H_INCLUDED
