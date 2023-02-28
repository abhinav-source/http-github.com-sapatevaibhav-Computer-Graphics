#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    for (int i = 0; i <= 800; i += 100)
    {
        line(0, i, 800, i);
        line(i, 0, i, 800);
    }
    line(799, 0, 799, 600);
    line(0, 599, 799, 599);

    setcolor(GREEN);
    outtextxy(0, 0, "0");
    outtextxy(100, 0, "100");
    outtextxy(200, 0, "200");
    outtextxy(300, 0, "300");
    outtextxy(400, 0, "400");
    outtextxy(500, 0, "500");
    outtextxy(600, 0, "600");
    outtextxy(700, 0, "700");
    outtextxy(800, 0, "800");

    outtextxy(0, 100, "100");
    outtextxy(00, 200, "200");
    outtextxy(00, 300, "300");
    outtextxy(00, 400, "400");
    outtextxy(00, 500, "500");
    outtextxy(00, 600, "600");
    outtextxy(00, 700, "700");
    outtextxy(00, 800, "800");

    setcolor(RED);
    // outtextxy(50, 50, "0");
    // outtextxy(150, 50, "1");
    // outtextxy(250, 50, "2");
    // outtextxy(350, 50, "3");
    // outtextxy(450, 50, "4");
    // outtextxy(550, 50, "5");
    // outtextxy(650, 50, "6");
    // outtextxy(750, 50, "7");

    char str[10];
    int j = 0;
    int y = 50;
    for (int i = 50; i <= 750; i += 100)
    {
        if (j < 48)
        {
            sprintf(str, "%d", j);
            outtextxy(i, y, str);
            delay(100);
            j++;
            printf("%d",j);

            if (y == 50 && i == 750)
            {
                y = 150;
                i = -50;
            }
            else if (y == 150 && i == 750)
            {
                y = 250;
                i = -50;
            }
            else if (y == 250 && i == 750)
            {
                y = 350;
                i = -50;
            }
            else if (y == 350 && i == 750)
            {
                y = 450;
                i = -50;
            }
            else if (y == 450 && i == 750)
            {
                y = 550;
                i = -50;
            }
        }
    }

    getch();
}