#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


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


    outtextxy(300, 300, "circle");

    outtextxy(60, 50, "line");
    line(10, 10, 100, 100);

    circle(300, 300, 100);

    outtextxy(500,500,"arc");
    arc(500, 500, 0, 200, 100);

    outtextxy(50,530,"rectangle");
    rectangle(40,450,300,550);

    outtextxy(500,150,"ellipse");
    ellipse(500,150,0,360,100,50);

    getch();

    closegraph();
    return 0;
}