#include <iostream>
#include "GUI.h"
#include "gotoxy.h"
#include "color.h"
#include <fstream>
#include <thread>
#include "Map.h"
using namespace std;
int posx, posy;
int score=0;
int Level=1;
void MapSave();
    int invalid(int x, int y)
    {
        if(arr[y-1][x-10]==1)
        return 1;
            return 0;
    }
class Pacman
{
    public:
    int x, y;
    Pacman(){}
    Pacman(int a, int b)
    {
        x=a;
        y=b;
        posx=x;
        posy=y;
        gotoxy(a, b);
        cout << "O";
    }
    void init(int a, int b)
    {
        x=a;
        y=b;
        posx=x;
        posy=y;
        gotoxy(a, b);
        cout << "O";
    }
    void Move()
    {
            if(GetAsyncKeyState(VK_ESCAPE))
            MapSave();
            else if(GetAsyncKeyState('W'))
            check(posx, posy-1, 'V');
            else if(GetAsyncKeyState('D'))
            check(posx+1, posy, '<');
            else if(GetAsyncKeyState('S'))
            check(posx, posy+1, 'A');
            else if(GetAsyncKeyState('A'))
            check(posx-1, posy, '>');

    }
   int check(int x, int y, char ch)
    {
        if(x<10||x>67||y>21||y<1||invalid(x, y))
            return 0;
             if(arr[y-1][x-10]==0)
            score++;
            arr[y-1][x-10]=2;
            gotoxy(posx, posy); cout << " ";
    if(y==21||y==20)
    {
    gotoxy(10, 21);
    SetColor(15);
    cout << "_________________________________________________________________";
    }
    posx=x;
    posy=y;
        gotoxy(posx, posy);
static int flag=0;
        if(flag==0)
        {cout << ch;flag=1;}
        else
        {cout << "O";flag=0;}
        return 1;
    }
};
class Enemy
{
    int en1x, en1y, Flag=0;
    public:
        Enemy()
        {
            en1x = 10 + (rand() % (int)(62));
            en1y = 10 + (rand() % (int)(18));
        }
    Enemy(int x, int y)
    {
        en1x=x;
        en1y=y;
    }
    int Move()
    {
        if(en1x==posx&&posy==en1y)
            return 12;
if(Flag==0)
{Flag=1;return 0;}

        if(posy>en1y)
            if(check(en1x, en1y+1)==0)
            check(en1x, en1y-1);
        if(posy<en1y)
           if(check(en1x, en1y-1)==0)
            check(en1x+1, en1y);
        if(posx>en1x)
            if(check(en1x+1, en1y)==0)
                check(en1x-1, en1y);
        if(posx<en1x)
            check(en1x-1, en1y);
            Flag=0;

    }
    int ifLost()
    {
        if(en1x==posx&&en1y==posy)
            return 1;
        return 0;
    }
int check(int x, int y)
    {
        if(x<10||x>67||y>21||y<1||invalid(x, y))
            return 0;
     gotoxy(en1x, en1y);
     SetColor(14);
      if(arr[y-1][x-12]==0)
   printf("%c", 505);
 else
    printf(" ");
    if(y==21||y==20)
    {
    gotoxy(10, 21);
 SetColor(15);
    cout << "________________________________________________________";
    }
    en1x=x;
    en1y=y;
        gotoxy(en1x, en1y);
        SetColor(12);
        cout << "X";
        SetColor(10);
        return 1;
    }

};
void MapSave()
{
    ofstream file1;
    file1.open("Resume.tds", ios::out);
    for(int i=0;i<20;i++){
        for(int j=0;j<55;j++)
        {
            if(arr[i][j]==0)
        file1 << ".";
        else if(arr[i][j]==1)
            file1 << "#";
            else if(arr[i][j]==2)
                file1 << " ";
        }
        file1 << "\n";
    }
    ofstream file2;
    file2.open("ResumeScore.tds", ios::out);
    file2 << score << "\n";
    file2 << Level << "\n";
    file2 << posx << "\n";
    file2 << posy;
    file2.close();
    exit(0);
}
int Initialize()
{
int i;    gotoxy(25, 10);
cout << "Press 1 To Reload Saved Game";
    gotoxy(25, 11);
    cout << "Press 2 To Start New Game";
cin >> i;
return i;
}
int main()
{
GetFrame();
    Enemy en[100];
int init=Initialize();
Pacman pacman;
if(init==1)
{
    ifstream file1;
file1.open("ResumeScore.tds", ios::in);
string str;
getline(file1, str);
score=stoi(str);
getline(file1, str);
Level=stoi(str);
getline(file1, str);
int jx=stoi(str);
getline(file1, str);
int jy=stoi(str);
pacman.init(jx, jy);
}
else if(init==2)
{
pacman.init(14, 5);
}
Map maps(11, 4, init);
int flag=0;
        int lo=0;
gotoxy(10, 25);
while(true)
{
    pacman.Move();
    gotoxy(69, 5);
    printf("Score : %d ", score);
    gotoxy(69, 6);
    printf("Level : %d   ", Level);
    gotoxy(69,10);
    printf("Developer:");
    gotoxy(69, 11);
           printf("Tarun Narain");
    if(score%100==0){Level++;score++;}
        for(int i=0;i<=Level;i++)
           {
               if(en[i].ifLost())
               {lo=1; break;}
               en[i].Move();
            }    Sleep(140);
            if(lo)
                break;
}
Beep(2750, 100);
while(true)
{
    gotoxy(32, 11); SetColor(12); cout << "Game Over";}
    return 0;
}
