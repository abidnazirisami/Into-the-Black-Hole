#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#define getmaxwidth() 1280
#define getmaxheight() 720

struct sco
{
    char name[50];
    char score[20];
} aaa[100],tmp;

FILE *f,*t;

void sort()
{
    int i,j,max;

    for(i=0; i<100; i++)
    {
        max=i;
        for(j=i+1; j<100; j++)
        {
            int m=strlen(aaa[j].score),n=strlen(aaa[max].score);
            if( m > n) max=j;
            else if(m==n)
            {
                int k=strcmp(aaa[j].score,aaa[max].score);
                if(k>0) max=j;
            }
        }
        tmp=aaa[i];
        aaa[i]=aaa[max];
        aaa[max]=tmp;
    }
}

void leaderboard()
{
    cleardevice();
    readimagefile("lb.jpg",0,0,getmaxwidth(),getmaxheight());
    f=fopen("input.txt","r");
    for(int g=0; g<10; g++)
    {
        fscanf(f,"%s",aaa[g].name);
        fscanf(f,"%s",aaa[g].score);
    }
    sort();
    fclose(f);
    int q=100,w=100,j;
    char a,b[3]= {0},c[50],d[50];
    settextstyle(0,0,4);
    setcolor(15);
    outtextxy(q,w,"Name");
    outtextxy(q+500,w,"Score");
    settextstyle(1,0,2);
    for(j=1; j<=10; j++)
    {
        b[0]=48+(j/10);
        b[1]=48+(j%10);
        outtextxy(q-50,w+(j*50),b);
        outtextxy(q,w+(j*50),aaa[j-1].name);
        outtextxy(q+500,w+(j*50),aaa[j-1].score);
    }
    settextstyle(0,0,0);
    setcolor(15);
    outtextxy(getmaxwidth()-400,getmaxheight()-100,"Press escape to go back to menu");
    while(1)
    {
        a = getch();
        if(a==27) break;
    }
}

void gameover(char score[20])
{
    while(kbhit())
        char chra = getch();
    clearmouseclick(WM_LBUTTONDOWN);
    readimagefile("hs.jpg",0,0,getmaxwidth(),getmaxheight());
    f=fopen("input.txt","r");
    for(int g=0; g<10 ; g++)
    {
        fscanf(f,"%s",aaa[g].name);
        fscanf(f,"%s",aaa[g].score);
    }
    sort();
    fclose(f);
    t=fopen("input.txt","w");
    setcolor(WHITE);
    settextstyle(0,0,0);
    outtextxy(200,300,"ENTER YOUR NAME:");
    char name[50]= {0};
    int ii;
    for(ii=0;; ii++)
    {
        name[ii]=getch();
        if(name[ii]==13 || name[ii] == 32) break;
        else if(name[ii] == 8)
        {
            ii-=2;
            readimagefile("hs.jpg",0,0,getmaxwidth(),getmaxheight());
            outtextxy(200,300,"ENTER YOUR NAME:");
        }
        name[ii+1]='|';
        name[ii+2] = 0;
        outtextxy(200,340,name);
        //printf("%s\n", name);
    }
    name[ii]=0;
    if(strcmp(aaa[9].score, score) < 0)
    {
        strcpy(aaa[9].score, score);
        strcpy(aaa[9].name, name);
        sort();
    }
    for(ii=0; ii<10; ii++)
    {
        fprintf(t,"%s %s\n",aaa[ii].name,aaa[ii].score);
    }
    //fprintf(t,"%s %s\n",name,score);
    fclose(t);
    leaderboard();
}
