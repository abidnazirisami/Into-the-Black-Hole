#include <graphics.h>
#include <stdio.h>
#include "ingame.h"
#include "menu.h"
#define getmaxwidth() 1280
#define getmaxheight() 720

int mora = 0;
struct enemy_centre
{
    int x,y;
    int status;
} abc[20];

int bachamora() //This function will tell us if our plane is destroyed or not
{
    if(mora == 0)
    {
        return 1;
    }
    else
    {
        mora = 0;
        return 0;
    }
}

void initialize1(int l)
{
    int m=getmaxwidth(),n=getmaxheight();
    abc[0].x=m-200;
    abc[0].y=n-550;
    abc[1].x=m-350;
    abc[1].y=n-300;
    abc[2].x=m-520;
    abc[2].y=n-200;
    abc[3].x=m-200;
    abc[3].y=n-650;
    abc[4].x=m-620;
    abc[4].y=n-100;
    abc[5].x=m-600;
    abc[5].y=n-400;
    abc[6].x=m-720;
    abc[6].y=n-500;
    abc[7].x=m-750;
    abc[7].y=n-350;
    abc[8].x=m-520;
    abc[8].y=n-600;
    abc[9].x=m-210;
    abc[9].y=n-250;
    for(int i = 0; i<10; i++)
    {
        abc[i].status = l;
    }
}

void initialize2(int l)
{
    int m=getmaxwidth(),n=getmaxheight();
    abc[3].x=m-100;
    abc[3].y=n-550;
    abc[7].x=m-450;
    abc[7].y=n-300;
    abc[0].x=m-20;
    abc[0].y=n-200;
    abc[8].x=m-500;
    abc[8].y=n-645;
    abc[9].x=m-620;
    abc[9].y=n-100;
    abc[6].x=m-400;
    abc[6].y=n-400;
    abc[5].x=m-720;
    abc[5].y=n-525;
    abc[12].x=m-750;
    abc[12].y=n-150;
    abc[1].x=m-20;
    abc[1].y=n-600;
    abc[4].x=m-210;
    abc[4].y=n-250;
    abc[2].x=m-100;
    abc[2].y=n-125;
    abc[11].x=m-300;
    abc[11].y=n-500;
    abc[10].x=m-700;
    abc[10].y=n-325;

    for(int i = 0; i<13; i++)
    {
        abc[i].status = l;
    }
}

void initialize3(int l)
{
    int m = getmaxwidth();
    abc[0].x=m-760;
    abc[0].y=475;
    abc[1].x=m-700;
    abc[1].y=295;
    abc[2].x=m-660;
    abc[2].y=385;
    abc[3].x=m-560;
    abc[3].y=205;
    abc[4].x=m-500;
    abc[4].y=250;
    abc[5].x=m-460;
    abc[5].y=520;
    abc[6].x=m-400;
    abc[6].y=70;
    abc[7].x=m-360;
    abc[7].y=115;
    abc[8].x=m-300;
    abc[8].y=655;
    abc[9].x=m-260;
    abc[9].y=565;
    abc[10].x=m-200;
    abc[10].y=430;
    abc[11].x=m-160;
    abc[11].y=610;
    abc[12].x=m-100;
    abc[12].y=340;
    abc[13].x=m-60;
    abc[13].y=160;

    for(int i = 0; i<14; i++)
    {
        abc[i].status = l;
    }
}

void level1()
{

    char number[4];

    for(int z=0; z<10; z++)
    {
        if(abc[z].status == 0)
        {
            readimagefile("TE.gif", abc[z].x-60,abc[z].y-60,abc[z].x+60,abc[z].y+60);
            delay(200);
            pregb();
            readimagefile("Pause1.jpg", abc[z].x-70,abc[z].y-60,abc[z].x+60,abc[z].y+60);
            pregb();
            abc[z].y = 100000;

        }
    }
    bg(WHITE);
    for(int z=0; z<10; z++)
    {
        if(abc[z].status > 0)
            enemy(abc[z].x,abc[z].y);
        /*number[0]=z+48;
        number[1]=0;
        setcolor(15);
        outtextxy(abc[z].x,abc[z].y,number);*/
    }


}

void level2()
{
    char number[4];

    for(int z=0; z<13; z++)
    {
        if(abc[z].status == 0)
        {
            readimagefile("TE.gif", abc[z].x-60,abc[z].y-30,abc[z].x+20,abc[z].y+30);
            delay(200);

            readimagefile("Pause1.jpg", abc[z].x-60,abc[z].y-27,abc[z].x+20,abc[z].y+30);

            abc[z].y = 100000;

        }
    }
    bg(WHITE);
    for(int z=0; z<13; z++)
    {
        if(abc[z].status > 0)
            enemy2(abc[z].x,abc[z].y);
        /*number[0]=z%9 + 48;
        number[1]=0;
        setcolor(15);
        outtextxy(abc[z].x,abc[z].y,number);*/
    }


}

void level3()
{

    char number[4];

    for(int z=0; z<14; z++)
    {
        if(abc[z].status == 0)
        {
            readimagefile("TE.gif", abc[z].x-60,abc[z].y-20,abc[z].x+15,abc[z].y+30);
            delay(200);
            pregb();
            readimagefile("Pause1.jpg", abc[z].x-60,abc[z].y-20,abc[z].x+15,abc[z].y+30);
            pregb();
            abc[z].y = 100000;

        }
    }
    bg(WHITE);
    for(int z=0; z<14; z++)
    {
        if(abc[z].status > 0)
            enemy3(abc[z].x,abc[z].y);
        /*number[0]=z%9+48;
        number[1]=0;
        setcolor(15);
        outtextxy(abc[z].x,abc[z].y,number);*/
    }


}



int limitguli = 10;
int core(int planex, int planeh, int health, int level, int score) // This is the function that actually loads when the game starts
{
    gulilimit(limitguli);
    int rv=0,z,j, enemycnt, gulistat = 0, gulih, guliw, enemyx, enemyy,det=0, ditto=1, enrangex, enrangey, enumb, gd, lasercount = 0;
    if(level == 1) gd = 20;
    else if(level == 2) gd = 30;
    else if(level == 3) gd = 30;
    if(level == 1) enumb = 10;
    else if(level == 2) enumb = 13;
    else if(level == 3) enumb = 14;
    enemycnt = enumb;
    if(level==1)
        enrangex=40,enrangey=40;
    else if(level ==2)
        enrangex=20,enrangey=20;
    else if(level ==3)
        enrangex=12,enrangey=28;
    prehb();
    for(z=0;; z=(z+3)%enumb)
    {
        if(lasercount ==  0)
            readimagefile("ls.jpg", 730,9,850,46);
        /*for(int i=0; i<enumb; i++)
        {
            if(abc[i].status ==0)
            {
                if(level==1)
                    level1();
                else if(level==2)
                    level2();
                abc[i].status--; // Otherwise every time it will load levels as status stays 0
                score+=10;
                enemycnt--;
                scoreboard(score);
            }
        }*/
        char number [10];
        for(j=abc[z].x; j>141;)
        {
            for(int i=0; i<enumb; i++)
        {
            /*number[0]=abc[i].status%9 + 48;
        number[1]=0;
        setcolor(15);
        outtextxy(abc[i].x,abc[i].y,number);*/
            if(abc[i].status ==0)
            {
                if(level==1)
                    level1();
                else if(level==2)
                    level2();
                else if(level==3)
                    level3();
                abc[i].status--; // Otherwise every time it will load levels as status stays 0
                score+=10;
                enemycnt--;
                scoreboard(score);
                int aa[] = {j-69,abc[i].y,j-71,abc[i].y-2,j-79,abc[i].y,j-71,abc[i].y+2,j-69,abc[i].y};
                setcolor(BLUE);
                circle(j-71,abc[i].y,2);
                drawpoly(5,aa);
            }
        }
            char aaa;

            if(abc[z].status > 0)
            {
                int a[] = {j-69,abc[z].y,j-71,abc[z].y-2,j-79,abc[z].y,j-71,abc[z].y+2,j-69,abc[z].y};
                if(ditto==1) {
                    setcolor(YELLOW);
                    circle(j-71,abc[z].y,2);
                    drawpoly(5,a);
                    ditto=0;
                }

                //delay(20);
                else if(ditto == 0) {
                setcolor(0);
                circle(j-71,abc[z].y,2);
                drawpoly(5,a);
                ditto=1;
                j-=20;
                }

            }
            else
            {
                break;
            }

            if(kbhit())
            {
                aaa=getch();
                if(aaa == 27)
                {
                    while(!kbhit())
                    {
                        readimagefile("Pause2.jpg", (getmaxwidth()/2)-100,getmaxheight()-40,(getmaxwidth()/2)+100,getmaxheight());
                        delay(300);
                        readimagefile("Pause1.jpg", (getmaxwidth()/2)-100,getmaxheight()-40,(getmaxwidth()/2)+100,getmaxheight());
                        delay(300);
                    }
                    char ch = getch();
                }
                else if(aaa=='s' && gulistat == 0 && limitguli)
                {
                    //planeh = guli(planex, planeh, aaa);
                    limitguli--;
                    gulilimit(limitguli);
                    gulistat = 1;
                    gulih = planeh;
                    guliw = planex;
                    for(int i = 0; i < enumb; i++)
                    {
                        if(gulih+15 <= abc[i].y+enrangey && gulih+15 >= abc[i].y-enrangex && abc[i].status>0)
                        {
                            enemyx = i;
                        }
                        if(gulih+35 <= abc[i].y+enrangey && gulih+35 >= abc[i].y-enrangex && abc[i].status>0)
                        {
                            enemyy = i;
                        }

                    }
                }
                else if(aaa=='a' && lasercount==0)
                {
                    laser(planex, planeh);
                    readimagefile("ll.jpg", 730,9,850,46);
                    lasercount=50;
                    for(int i = 0; i < enumb; i++)
                    {
                        if(planeh+22 <= abc[i].y+enrangey && planeh+26 >= abc[i].y-enrangex && abc[i].status>0)
                        {
                            abc[i].status-=5;
                            if(abc[i].status<0)
                                abc[i].status = 0;

                        }
                    }
                }
                else if(planeh>45&&aaa==KEY_UP)
                {
                    move(planex, planeh, aaa,COLOR(128,128,128));
                    planeh-=10; // We could also take the original height as input, but we know what happens already, so why bother? :p
                }
                else if(planeh+62<getmaxheight()&&aaa==KEY_DOWN)
                {
                    move(planex, planeh, aaa,COLOR(128,128,128));
                    planeh+=10;
                }
            }
            if(gulistat == 1)
            {
                if(det == 0) {
                    gulih = guli(guliw, gulih, 's', 0);
                    gulih = guli(guliw-2, gulih, 's', 0);
                    det = 1;
                }
                else if(det == 1) {
                    gulih = guli(guliw, gulih, 's', YELLOW);
                    gulih = guli(guliw-2, gulih, 's', COLOR(255,4,4));
                    det = 0;
                }
                {
                    if(guliw >= abc[enemyx].x-100-gd && abc[enemyx].status>0)
                    {
                        gulih = guli(guliw, gulih, 's', 0);
                        gulih = guli(guliw-2, gulih, 's', 0);
                        abc[enemyx].status-=5;
                        gulistat = 0;
                        if(abc[enemyx].status<0)
                            abc[enemyx].status=0;
                    }
                    if(guliw >= abc[enemyy].x-100-gd && abc[enemyy].status > 0)
                    {
                        gulih = guli(guliw, gulih, 's', 0);
                        gulih = guli(guliw-2, gulih, 's', 0);
                        abc[enemyy].status-=5;
                        if(abc[enemyy].status<0)
                            abc[enemyy].status=0;
                        gulistat = 0;
                    }

                }
                if(guliw >= getmaxwidth())
                    gulistat = 0;
                if(det==1)
                    guliw +=20;

            }
            if(lasercount!=0)
                lasercount--;
            delay(10);
        }
        if(abc[z].y <= planeh+60 && abc[z].y >= planeh-10 && abc[z].status > 0){ // Searches if the guli is within the range of the plane
            rv = 1;
            setcolor(0);
            int a[] = {j-69,abc[z].y,j-71,abc[z].y-2,j-79,abc[z].y,j-71,abc[z].y+2,j-69,abc[z].y};
            circle(j-71,abc[z].y,2);
            drawpoly(5,a);
            ditto=1;
        }
        else {
            rv = 0;
            setcolor(0);
            int a[] = {j-69,abc[z].y,j-71,abc[z].y-2,j-79,abc[z].y,j-71,abc[z].y+2,j-69,abc[z].y};
            circle(j-71,abc[z].y,2);
            drawpoly(5,a);
            ditto=1;
        }
        health-=rv;
        if(rv)
        {
            score -= rv*5;
            scoreboard(score);
            healthbar(health);
        }
        //Prints the updated Health bar
        if(!health)
        {
            readimagefile("TE.gif", planex-10,planeh-10,planex+70,planeh+60);
            delay(2000);
        }
        if(!health || !enemycnt)
        {
            if(!health)
            {
                mora = 1;
            }
            rv = score;
            break;
        }


    }
    limitguli+=10;
    return rv;
}


