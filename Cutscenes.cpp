#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "menu.h"
#include "ingame.h"
#define getmaxwidth() 1280
#define getmaxheight() 720
#include "cutscenes.h"

struct enemy_centre
{
    int x,y;
    int status;
} ab[20];

void starsmove()
{

    stars(WHITE);
    bg(WHITE);
}

void dialogue(int time)
{

    if(time==0)
    {
        readimagefile("D.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    }
    else if(time == 1)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 2)
        readimagefile("D-001.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 3)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 4)
        readimagefile("D-002.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 5)
        readimagefile("D-003.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 6)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 7)
        readimagefile("D-004.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 8)
        readimagefile("D-005.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 9)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 10)
        readimagefile("D-006.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 11)
        readimagefile("D-007.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 12)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 13)
        readimagefile("D-008.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 14)
        readimagefile("D-009.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 15)
        readimagefile("D-010.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 16)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 17)
        readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 18)
        readimagefile("D-011.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 19)
        readimagefile("D-012.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);


}

int cutscene1(int d)
{
    loadingscreen();
    cloadingscreen();
    int cnt=0;
    primee();
    cleardevice();
    void *pt, *qt;
    pt=malloc(imagesize(0,100,getmaxwidth(),getmaxheight()-100));
    qt=malloc(imagesize(0,0,getmaxwidth(),getmaxheight()));
    starsmove();
    getimage(0,100,getmaxwidth(),getmaxheight()-100,pt);
    getimage(0,0,getmaxwidth(),getmaxheight(),qt);
    cleardevice();
    for(int i=getmaxwidth(); cnt<=400; i-=16)
    {
        if(kbhit())
        {
            //cleardevice();
            char c= getch();
            if(c == 27)
            {
                free(pt);
                free(qt);

                return 0;
            }
        }
        if(i==0)
            i = getmaxwidth();
        putimage(i,100,pt,0);
        putimage(i-getmaxwidth(),100,pt,0);
        plane(10,getmaxheight()/2, COLOR(128,128,128));

        dialogue(cnt/20);

        delay(d);
        cnt++;
    }
    int m=getmaxwidth(),n=getmaxheight();
    ab[0].x=m-200;
    ab[0].y=n-550;
    ab[1].x=m-350;
    ab[1].y=n-300;
    ab[2].x=m-520;
    ab[2].y=n-200;
    ab[3].x=m-200;
    ab[3].y=n-650;
    ab[4].x=m-620;
    ab[4].y=n-100;
    ab[5].x=m-600;
    ab[5].y=n-400;
    ab[6].x=m-720;
    ab[6].y=n-500;
    ab[7].x=m-750;
    ab[7].y=n-350;
    ab[8].x=m-520;
    ab[8].y=n-600;
    ab[9].x=m-210;
    ab[9].y=n-250;
    for(int i=850; i>=0; i-=25)
    {
        putimage(0,0,qt,0);
        plane(10,getmaxheight()/2, COLOR(128,128,128));
        for(int j=0; j<10; j++)
        {
            enemy(ab[j].x+i, ab[j].y);
        }
        delay(100);

    }
    delay(3000);
    readimagefile("D-013.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    delay(3000);
    readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    delay(1000);
    readimagefile("D-014.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    delay(3000);
    readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    delay(3000);
    free(pt);
    free(qt);
    //loadingscreen();
    return 0;
}

void dialogue2(int time)
{
    if(time==0) readimagefile("D21.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 1) readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if (time == 2) readimagefile("D22.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if (time == 3) readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 4) readimagefile("D231.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 5) readimagefile("D232.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 6) readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 7) readimagefile("D24.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 8) readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 9) readimagefile("D25.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 10) readimagefile("DB.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
    else if(time == 11) readimagefile("D26.jpg", 300, getmaxheight()-100, getmaxwidth()-300, getmaxheight()-50);
}


int cutscene2(int d)
{
    cloadingscreen();
    int cnt=0;
    primee();
    cleardevice();
    void *pt2, *qt2;
    pt2=malloc(imagesize(0,100,getmaxwidth(),getmaxheight()-100));
    qt2=malloc(imagesize(0,0,getmaxwidth(),getmaxheight()));
    starsmove();
    getimage(0,100,getmaxwidth(),getmaxheight()-100,pt2);
    getimage(0,0,getmaxwidth(),getmaxheight(),qt2);
    cleardevice();
    for(int i=getmaxwidth(); cnt<=240; i-=16)
    {
        if(kbhit())
        {
            //cleardevice();
            char c= getch();
            if(c == 27)
            {
                free(pt2);
                free(qt2);

                return 0;
            }
        }
        if(i==0)
            i = getmaxwidth();
        putimage(i,100,pt2,0);
        putimage(i-getmaxwidth(),100,pt2,0);
        plane(10,getmaxheight()/2, COLOR(128,128,128));

        dialogue2(cnt/20);

        delay(d);
        cnt++;
    }
    free(pt2);
    free(qt2);
}
