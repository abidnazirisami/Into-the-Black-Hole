#include <graphics.h>
#include <stdio.h>
#include <math.h>
#define getmaxwidth() 1280
#define getmaxheight() 720

int prime[10000]={0};

void primee()
{

    int k, j;
    for(j=4; j<=10000; j+=2) prime[j] = 1;
    for(j=3; j<=sqrt(10000); j+=2)
    {
        if(prime[j] == 0)
        {
            for(k=j+j; k<=10000; k+=j)
                prime[k] = 1;
        }
    }
    prime[0] = 1, prime[1] = 1;

}

void stars(int col) // Left side bg
{
    int j,xx=0,yy=0;

    setcolor(col);

    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx+(j%7)*j <= 70)
        {
            circle(xx+(j%7)*j,yy+(j%3)*j, 1);
        }
    }
    xx = getmaxwidth();
    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx-(j%7)*j <= 70)
        {
            circle(xx-(j%7)*j,yy+(j%3)*j, 1);
        }
    }
    xx=0;
    yy=getmaxheight();
    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx+(j%7)*j <= 70)
        {
            circle(xx+(j%7)*j,yy-(j%3)*j, 1);
        }
    }
    xx=getmaxwidth();
    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx-(j%7)*j <= 70)
        {
            circle(xx-(j%7)*j,yy-(j%3)*j, 1);
        }
    }

}

void bg(int col) //main bg
{
    int j,xx=0,yy=0;

    setcolor(col);

    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx+(j%7)*j >70)
        {
            circle(xx+(j%7)*j,yy+(j%3)*j, 1);
        }
    }
    xx = getmaxwidth();
    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx+(j%7)*j >70)
        {
            circle(xx-(j%7)*j,yy+(j%3)*j, 1);
        }
    }
    xx=0;
    yy=getmaxheight();
    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx+(j%7)*j >70)
        {
            circle(xx+(j%7)*j,yy-(j%3)*j, 1);
        }
    }
    xx=getmaxwidth();
    for(j=1; j<=getmaxwidth(); j++)
    {

        if(prime[j] == 0 && xx+(j%7)*j >70)
        {
            circle(xx-(j%7)*j,yy-(j%3)*j, 1);
        }
    }

}

