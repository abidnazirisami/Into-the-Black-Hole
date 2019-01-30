#include <graphics.h>
#include <stdio.h>
#include "ingame.h"
#define getmaxwidth() 1280
#define getmaxheight() 720


int i=10;

void plane(int x, int y, int col)
{
    int a[16] = {x,y,x,y+15,x+5,y+15,x+5,y+35,x,y+35,x,y+50,x+60,y+25,x,y};
    int can[4] = {x, y+10, x+40, y+10};
    int can2[4] = {x, y+40, x+40, y+40};
    int b2[4] = {x,y+15,x+60,y+15};
    int b3[4] = {x, y+35, x+60, y+35};

    setcolor(col);

    drawpoly(8, a);

    setfillstyle(1, col);
    floodfill(x+1,y+1,col);

    setfillstyle(1, col);
    floodfill(x+6,y+16,col);

    setfillstyle(1, col);
    floodfill(x+1,y+46,col);

    drawpoly(2, can);
    drawpoly(2, can2);

    setcolor(0);

    drawpoly(2, b2);
    drawpoly(2,b3);
}


void move(int x, int y, char c, int col)
{
    if(c==KEY_UP && y>45)
    {
        plane(x, y, 0);
        stars(WHITE);
        y-=i;
        plane(x, y, col);

    }

    else if(c==KEY_DOWN && y+62<getmaxheight())
    {

        plane(x, y, 0);
        stars(WHITE);
        y+=i;
        plane(x, y, col);

    }
}

int guli(int x, int y, char c, int col)
{
    int xa = x, ya = y;
    //setcolor(YELLOW);
    if(c=='s')
    {
        setcolor(col);
        int j = 0;


        int a[] = {xa+58+j,ya+15,xa+60+j,ya+13,xa+68+j,ya+15,xa+60+j,ya+17,xa+58+j,ya+15};
        int b[] = {xa+58+j,ya+35,xa+60+j,ya+33,xa+68+j,ya+35,xa+60+j,ya+37,xa+58+j,ya+35};
        drawpoly(5, b);
        circle(xa+60+j,ya+15,2);
        circle(xa+60+j,ya+35,2);
        drawpoly(5, a);
        //delay(30);
        /*setcolor(0);

        drawpoly(5, b);
        circle(xa+60+j,ya+15,2);
        circle(xa+60+j,ya+35,2);
        drawpoly(5, a);
        setcolor(YELLOW);*/

    }


    return y;
}

void laser(int x, int y)
{
    int xa = x, ya = y;
    void *ptr;
    ptr=malloc(imagesize(0,0,getmaxwidth(),getmaxwidth()));
    for(int j=0; xa+60+j<getmaxwidth()+500; j+=500)
    {

        getimage(0,0,getmaxwidth(),getmaxheight(),ptr);
        readimagefile("laser.gif", xa+61, ya + 22, xa+75+j, ya+26);
        delay(20);
        putimage(0,0,ptr,0);
    }
    free(ptr);
}


void enemy(int a,int b)
{
    setcolor(CYAN);
    ellipse(a, b, 30, 150, 50, 30);
    ellipse(a, b, 20, 160, 60, 40);
    ellipse(a, b, 210, -30, 50, 30);
    ellipse(a, b, 200, -20, 60, 40);
    line(a-43,b+13, a-57, b+13);
    line(a-43,b-13, a-57, b-13);
    line(a+43,b+13, a+57, b+13);
    line(a+43,b-13, a+57, b-13);
    line(a-40,b,a-70,b);
    line(a-40,b-1,a-60,b-1);
    line(a-40,b+1,a-60,b+1);
    setfillstyle(1,COLOR(128,128,128));
    fillellipse(a,b,40,20);
    setcolor(0);
    circle(a-14,b,1);
    circle(a-7,b+5,1);
    circle(a,b+6,1);
    circle(a+14,b,1);
    circle(a+7,b+5,1);
    circle(a+7,b-5,1);
    circle(a,b-6,1);
    circle(a-7,b-5,1);
    //return 0;
}

void enemy2(int a, int b)
{
    setcolor(WHITE);
    setfillstyle(1, COLOR(255,4,4));
    int mw = getmaxwidth();
    int x = mw-a;
    int y = b - 20;
    int e2[] = {mw-x, y, mw-x-10,y+8,mw-x,y+8,mw-x,y+32,mw-x-10,y+32,mw-x,y+40,mw-x-45,y+40,mw-x-50,y+30,mw-x-55,y+30,mw-x-60,y+20,mw-x-55,y+10,mw-x-50,y+10,mw-x-45,y,mw-x,y};
    fillpoly(14, e2);
    line(mw-x-50+3,y+10+3,mw-x-50+3,y+30-3);
    line(mw-x-50+8,y+10+3,mw-x-50+8,y+30-3);
    line(mw-x-50+13,y+10+3,mw-x-50+13,y+30-3);
}

void enemy3(int x, int y)
{
    setcolor(WHITE);
    setfillstyle(3, COLOR(0,76,153));
    int e2[] = {x,y,x,y+16,x-12,y+28,x-48,y+28,x-60,y+16,x-40,y+16,x-40,y,x-60,y,x-48,y-12,x-12,y-12,x,y};
    fillpoly(11, e2);
}
