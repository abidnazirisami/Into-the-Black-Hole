#include <graphics.h>
#include <stdio.h>
#include "menu.h"
#include "ingame.h"
#include "cutscenes.h"
#define getmaxwidth() 1280
#define getmaxheight() 720

int health = 10, width = 10, height = getmaxheight()/2, score = 0;

int main()
{
    int count=0,test,l1=10,l2=15,l3=25;
    initwindow(getmaxwidth(),getmaxheight(), "Into The Blackhole");
    animatedstart();

    while(1)
    {
        test=menu();
        if(test==1)
        {


            int bla = cutscene1(150);
            int score=0,lvl=1;
            char c;
            while(1)
            {
            //if(lvl==1)

            if(lvl == 1) initialize1(l1);
            else if(lvl == 2) initialize2(l2);
            else if(lvl == 3) initialize3(l3);
            cleardevice();
            if(lvl==1||lvl==2||lvl==3)
            {
                primee();
                stars(WHITE);
                bg(WHITE);
            }

                if(lvl==1)level1();
                else if(lvl==2) level2();
                else if(lvl==3) level3();

                plane(width, height, COLOR(128,128,128));
                pregb();
                prehb();
                presb();
                readimagefile("ls.jpg", 730,9,850,46);
                scoreboard(score);
                healthbar(health);

                readimagefile("Pause1-001.jpg", (getmaxwidth()/2)-100,getmaxheight()-40,(getmaxwidth()/2)+100,getmaxheight());
                char ch = getch();
                readimagefile("Pause1.jpg", (getmaxwidth()/2)-100,getmaxheight()-40,(getmaxwidth()/2)+100,getmaxheight());

                score = core(width, height,health,lvl, score);
                if(!bachamora()) // When healthbar is empty
                {
                    setcolor(WHITE);
                    settextstyle(3,HORIZ_DIR,10);
                    //outtextxy((getmaxwidth()/2)-300,(getmaxheight()/2)-50,"GAME OVER");
                    cleardevice();
                    readimagefile("gameover.jpg",0,0,getmaxwidth(),getmaxheight());
                    delay(2000);
                    char scores[20];
                    sprintf(scores, "%d", score);// Converts int into string
                    gameover(scores);
                    health = 10; // So that if player wants to start another game, he gets full healthbar
                    break;
                }

                else if(bachamora()) //If the plane completes any level
                {
                    setcolor(WHITE);
                    cleardevice();

                    readimagefile("Level1C1.jpg",0,0,getmaxwidth(),getmaxheight());

                    delay(1000);
                    if(lvl == 1)
                    readimagefile("Level1C2.jpg",0,0,getmaxwidth(),getmaxheight());
                    else if(lvl == 2)
                    readimagefile("Level2C2.jpg",0,0,getmaxwidth(),getmaxheight());
                    else if(lvl == 3)
                    readimagefile("Level3C2.jpg",0,0,getmaxwidth(),getmaxheight());
                    delay(1000);
                    /*char scores[20];
                    sprintf(scores, "%d", score);// Converts int into string
                    gameover(scores);
                    health = 10; // So that if player wants to start another game, he gets full healthbar
                    break;*/
                    lvl++;
                }


                if(lvl == 4)
                {
                    while(kbhit())
                        char chra = getch();
                    clearmouseclick(WM_LBUTTONDOWN);
                    readimagefile("Succcess.jpg", 0, 0, getmaxwidth(), getmaxheight());
                    char cmp = getch();
                    if(cmp == 13) {
                            lvl-=3;
                            l1*=2;
                            l2*=2;
                            l3*=2;
                            health=10;
                    }
                    else
                    {
                    char scores[20];
                    sprintf(scores, "%d", score);// Converts int into string
                    gameover(scores);
                    health = 10;
                    int au=cutscene2(150);// So that if player wants to start another game, he gets full healthbar
                    break;
                    }
                }

            }
        }
        else if(test==2)
        {
            leaderboard();
        }
        else break;
    }
    closegraph();
    return 0;
}
