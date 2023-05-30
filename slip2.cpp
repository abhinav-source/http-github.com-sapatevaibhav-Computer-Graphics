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
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double slope = dy / dx;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    double xinc = dx / steps;
    double yinc = dy / steps;

    double x = p1.x;
    double y = p1.y;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; ++i)
    {
        if (i % 10 < 5)
        {
            glVertex2f(x, y);
        }
        x += xinc;
        y += yinc;
    }
    glEnd();
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
