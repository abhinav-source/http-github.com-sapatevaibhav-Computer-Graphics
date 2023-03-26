#include <graphics.h>
#include <stdio.h>

int main()
{

    int x1 = 200, y1 = 400, x2 = 100, y2 = 85, dx, dy, steps;

    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x1, Y = y1;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for (int i = 0; i <= steps; i++)
    {

        putpixel(X, Y, 2);
        delay(10);
        X += Xinc;
        Y += Yinc;
    }

    getch();
    closegraph();
    return 0;
}