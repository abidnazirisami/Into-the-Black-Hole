#include <graphics.h>
#include <stdio.h>
#define getmaxwidth() 1280
#define getmaxheight() 720
int menu()
{

    readimagefile("A-001.jpg",0,0,getmaxwidth(),getmaxheight());

    int q = 472, w = 320,flag;

    readimagefile("pk.gif",q-50,w,q-10,w+30);

    clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
        int x,y;
        x=mousex();
        y=mousey();
        if(x>q && x<q+248)
        {
            if(y>=w && y<w+30)
            {
                readimagefile("A-002.jpg",0,0,getmaxwidth(),getmaxheight());

                readimagefile("pk.gif",q-50,w,q-10,w+30);

                flag=1;
            }
            else if(y>=w+45 && y<w+75)
            {
                readimagefile("A-004.jpg",0,0,getmaxwidth(),getmaxheight());

                readimagefile("pk.gif",q-50,w+50,q-10,w+80);

                flag=2;
            }

            else if(y>=w+90 && y<w+120)
            {
                readimagefile("A-006.jpg",0,0,getmaxwidth(),getmaxheight());

                readimagefile("pk.gif",q-50,w+105,q-10,w+135);

                flag=0;
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(y>=w && y<w+45)
            {
                readimagefile("A-003.jpg", 0, 0, getmaxwidth(), getmaxheight());
                readimagefile("pk.gif",q-50,w,q-10,w+30);
                delay(100);
                readimagefile("A-002.jpg", 0, 0, getmaxwidth(), getmaxheight());
                readimagefile("pk.gif",q-50,w,q-10,w+30);
                delay(500);
                return 1;
            }
            else if(y>=w+45 && y<w+90)
            {
                readimagefile("A-005.jpg", 0, 0, getmaxwidth(), getmaxheight());
                readimagefile("pk.gif",q-50,w+50,q-10,w+80);
                delay(100);
                readimagefile("A-004.jpg", 0, 0, getmaxwidth(), getmaxheight());
                readimagefile("pk.gif",q-50,w+50,q-10,w+80);
                delay(500);
                return 2;
            }
            else if(y>=w+90 && y<w+120)
            {
                readimagefile("A-007.jpg", 0, 0, getmaxwidth(), getmaxheight());
                readimagefile("pk.gif",q-50,w+105,q-10,w+135);
                delay(100);
                readimagefile("A-006.jpg", 0, 0, getmaxwidth(), getmaxheight());
                readimagefile("pk.gif",q-50,w+105,q-10,w+135);
                delay(500);
                return 0;
            }

        }
    }
}

void prehb() // Loads the health bar
{
    setcolor(WHITE);
    int gg = getmaxwidth()-180;

    settextstyle(3,HORIZ_DIR,3);
    outtextxy((gg/2)-70,15,"Health: ");
    rectangle((gg/2)-80,9,(gg/2)+160, 46);
    line((gg/2)+161,9,(gg/2)+161,46);
    line((gg/2)+160,9,(gg/2)+160,46);
    line((gg/2)+159,9,(gg/2)+159,46);
    rectangle((gg/2)-80,9,(gg/2)-1,46);
}

void healthbar(int health) // Prints the current health of the spaceship
{
    setcolor(WHITE);
    int gg = getmaxwidth()-180,i;

    for(i=0; i<health; i++)
    {
        rectangle((gg/2),10,(gg/2)+16,45);
        setfillstyle(1, WHITE);
        floodfill((gg/2)+2, 12, WHITE);

        gg+=32;
    }
    setcolor(0);

    rectangle((gg/2),10,(gg/2)+16,45);
    setfillstyle(1,0);
    floodfill((gg/2)+2, 12, 0);
}

void animatedstart() //The animated starting of the game where the logo is shown for the first time
{
    readimagefile("1.jpg",0,0,getmaxwidth(),getmaxheight());
    for(int i=16; i<=640; i+=16)
    {

        readimagefile("Logo 2.gif",640-i,360-(i*9/16),640+i,360+(i*9/16));


    }

    readimagefile("1.jpg",0,0,getmaxwidth(),getmaxheight());
    readimagefile("Logo 2.gif",0,0,getmaxwidth(),getmaxheight());
    while(!kbhit())
    {
        delay(500);
        readimagefile("p2.jpg", 422, 577, 422+404, 577+44);

        delay(500);
        readimagefile("p1.jpg", 422, 577, 422+404, 577+44);

    }
    char c = getch();

    readimagefile("Loading (1).jpg", 422, 577, 422+404, 577+44);
    delay(500);
    readimagefile("Loading (2).jpg", 422, 577, 422+404, 577+44);
    delay(1000);
    readimagefile("Loading (3).jpg", 422, 577, 422+404, 577+44);
    delay(500);
}


void presb() //Loads the scoreboard
{
    setcolor(WHITE);
    int gg = getmaxwidth()-180;


    settextstyle(3,HORIZ_DIR,3);
    outtextxy((gg/2)-270,15,"Score: ");
    rectangle((gg/2)-280,9,(gg/2)-100, 46);

    rectangle((gg/2)-280,9,(gg/2)-201,46);
}

void scoreboard(int score) //Prints score on the scoreboard
{

    int gg = getmaxwidth()-180;
    char a[100];
    setcolor(0);
    int dhur[] = {(gg/2)-200,10,(gg/2)-101,10,(gg/2)-101,45,(gg/2)-200,45,(gg/2)-200,10};

    setfillstyle(1,0);

    fillpoly(5, dhur);
    setcolor(WHITE);
    settextstyle(3,HORIZ_DIR,3);
    sprintf(a, "%5d", score);
    outtextxy((gg/2)-180, 15, a);
}


void loadingscreen()
{
    readimagefile("h1.jpg", 0, 0, getmaxwidth(), getmaxheight());
    delay(1500);
    readimagefile("h2.jpg", 0, 0, getmaxwidth(), getmaxheight());
    delay(1500);
    readimagefile("h3.jpg", 0, 0, getmaxwidth(), getmaxheight());
    delay(1500);
}

void cloadingscreen() //Cut scene with hint to press esc to skip
{
    readimagefile("cl1.jpg", 0, 0, getmaxwidth(), getmaxheight());
    delay(1000);
    readimagefile("cl2.jpg", 0, 0, getmaxwidth(), getmaxheight());
    delay(1000);
    readimagefile("cl3.jpg", 0, 0, getmaxwidth(), getmaxheight());
    delay(1000);
}



void pregb() //Loads the scoreboard
{
    setcolor(WHITE);
    int gg = getmaxwidth();


    settextstyle(3,HORIZ_DIR,3);
    outtextxy((gg/2)+240,15,"Missiles: ");
    rectangle((gg/2)+230,9,(gg/2)+320, 46);

    rectangle((gg/2)+230,9,(gg/2)+380,46);
}

void gulilimit(int limit) //Prints score on the scoreboard
{

    int gg = getmaxwidth();
    char a[100];
    setcolor(0);
    int dhur[] = {(gg/2)+330,10,(gg/2)+370,10,(gg/2)+370,45,(gg/2)+330,45,(gg/2)+330,10};

    setfillstyle(1,0);

    fillpoly(5, dhur);
    setcolor(WHITE);
    settextstyle(3,HORIZ_DIR,3);
    sprintf(a, "%5d", limit);
    outtextxy((gg/2)+330, 15, a);
}

