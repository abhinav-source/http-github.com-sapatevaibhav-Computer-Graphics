// Implement Bresenham Line drawing algorithm to draw dashed line. Divide the screen in four quadrants with center as (0,0).

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

struct point
{
    GLint x;
    GLint y;
};

point p1, p2;

void bresenham(point p1, point p2)
{
    int x_2 = p2.x, x_1 = p1.x, y_1 = p1.y, y_2 = p2.y;
    int dx = abs(x_2 - x_1);
    int dy = abs(y_2 - y_1);
    int x = x_1;
    int y = y_1;
    int incx = (x_2 > x_1) ? 1 : -1;
    int incy = (y_2 > y_1) ? 1 : -1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    if (dx > dy)
    {
        int cnt = 1;
        int p = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            if (p >= 0)
            {
                y += incy;
                p -= 2 * dx;
            }
            x += incx;
            p += 2 * dy;

            if (cnt <= 10)
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }
            cnt++;
            if (cnt == 15)
            {
                cnt = 1;
            }
        }
    }
    else
    {
        int cnt = 1;
        int p = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            if (p >= 0)
            {
                x += incx;
                p -= 2 * dy;
            }
            y += incy;
            p += 2 * dx;

            if (cnt <= 10)
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }
            cnt++;
            if (cnt == 15)
            {
                cnt = 1;
            }
        }
    }

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham");
    init();

    glBegin(GL_LINES);
    glVertex2f(0, 240);
    glVertex2f(640, 240);
    glVertex2f(320, 0);
    glVertex2f(320, 480);
    glEnd();
    glFlush();

    cout << "\nEnter X1, Y1 Co-Ordinate : ";
    cin >> p1.x >> p1.y;
    cout << "\nEnter X2, Y2 Co-Ordinate : ";
    cin >> p2.x >> p2.y;
    p1.x += 320;
    p2.x += 320;
    p1.y += 240;
    p2.y += 240;

    glColor3f(0.0, 1.0, 1.0);
    bresenham(p1, p2);
    glutMainLoop();

    return 0;
}
