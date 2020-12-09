#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20;
const int length=20;
int x,y,fruitX,fruitY,score;
enum eDirection{STOP=0,RIGHT,LEFT,UP,DOWN};
eDirection dir;
void setup()
{
   int gameover=false;
    dir=STOP;
    x=width/2;
    y=length/2;
      fruitX=rand()%width;
        fruitY=rand()%length;
    score=0;
}
void draw()
{
    int i;
    system("cls");
    for( i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;
    for(i=0;i<length;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";
                if(i==y&&j==x)
                    cout<<"O";
                else if(i==fruitY&&j==fruitX)
                    cout<<"F";
                    else
            cout<<" ";
            if(j==width-1)
                cout<<"#";

        }
        cout<<endl;
    }
    for(i=0;i<width+2;i++)

        cout<<"#";
        cout<<endl;
        cout<<"Score:"<<score<<endl;

}
void input()
{
  if(_kbhit())
  {
      switch(_getch())
      {
      case'a':
        dir=LEFT;
        break;
      case'd':
          dir=RIGHT;
          break;
      case 's':
        dir=DOWN;
        break;
      case 'w':
        dir=UP;
        break;
      case'x':
        gameover=true;
        break;

      }
  }
}
void logic()
{
  switch(dir)
  {
   case LEFT:
    x--;
        break;
   case RIGHT:
    x++;
          break;
      case DOWN:
          y++;
        break;

      case UP:
          y--;
        break;

      default:
        break;
  }
  if(x>width||x<0||y>length<0)
    gameover=true;
    if(x==fruitX&&y==fruitY)
    {
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%length;

    }


}
int main()
{
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
       // sleep(10);
    }
    return 0;
}
