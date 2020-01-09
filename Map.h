#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include<fstream>
#include<iostream>
using namespace std;
int arr[100][100];
int lenx;
int leny;
class Map
{
public :
    Map(int x, int y, int choice)
    {
        gotoxy(x, y);
        ifstream file1;
        if(choice==2)
        file1.open("Level1.tds", ios::in);
        else
            file1.open("Resume.tds", ios::in);
        char ch;
        int line=1;
        int i=0,j=0;
        int hp=0;
        while(file1.get(ch))
        {

            if(ch=='\n')
         {line++; gotoxy(10, line); i++;hp=j; j=0; continue;}
            else if(ch=='#')
            {printf("%c", 257); arr[i][j]=1;}
            else if(ch=='.'){SetColor(14); printf("%c", 505); arr[i][j]=0; SetColor(15);}
           else if(ch==' '){SetColor(14); printf(" "); arr[i][j]=2; SetColor(15);}
            j++;
        }
        lenx=hp;
        leny=line;
    }
};


#endif // MAP_H_INCLUDED
