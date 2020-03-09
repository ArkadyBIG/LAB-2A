#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
//      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
const int text=3,press=115;
BOOL ShowConsoleCursor(BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if(!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if(!SetConsoleCursorInfo(hStdOut,&cci))
        return FALSE;
    return TRUE;
}
int choose(vector<string> s,bool ESC=0)
{
    ShowConsoleCursor(0);
    //if(s.size()<2) return -1;
    CONSOLE_SCREEN_BUFFER_INFO c;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),text);
    for(string a: s)
        cout<<a<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        if(ESC)
        cout<<"To go back press ESC";
    unsigned int cur=0;
    bool finish=0;
    while(!finish)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+cur});

        cout<<'\r';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),press);
        cout<<s[cur];

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        switch(_getch())
        {
        case 27:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+s.size()+1});
    ShowConsoleCursor(1);
    return -1;
            case 13:
                finish=1;
                break;
            case 72:
                if(cur!=0)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),text);
                    cout<<"\r";
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+cur});
                    for(int i=0;i<s[cur].size();++i)
                        cout<<' ';
                    cout<<'\r';

                    cout<<s[cur];

                    cur--;
                }
                break;
            case 80:
                if(cur< s.size()-1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),text);
                    cout<<"\r";
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+cur});
                    for(int i=0;i<s[cur].size();++i)
                        cout<<' ';
                    cout<<'\r';

                    cout<<s[cur];
                    cur++;
                    break;
                }
        }


    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"  <--"<<(char)253;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+s.size()});
    cout<<"\r                      \n";
    ShowConsoleCursor(1);
    return cur;

}
