// Implement DDA line drawing algorithm to draw solid line

#include <GL/glut.h>

void ddaLine(int x1, int y1, int x2, int y2)
{
    // Calculate the slope of the line.
    float m = (float)(y2 - y1) / (float)(x2 - x1);

    // Calculate the step size.
    float step = 1.0f;
    if (abs(m) > 1.0f)
    {
        step = 1.0f / abs(m);
    }

    // Initialize the current point.
    float x = x1;
    float y = y1;

    // Loop until the current point reaches the end of the line.
    while (x <= x2)
    {
        // Plot the current point.
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();

        // Update the current point.
        x += step;
        y += step * m;
    }
}

int main(int argc, char **argv)
{
    // Initialize GLUT.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Algorithm");

    // Set the background color.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Set the projection matrix.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    // Set the drawing color.
    glColor3f(1.0f, 1.0f, 1.0f);

    // Clear the color buffer.
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the line.
    ddaLine(100, 100, 400, 400);

    // Render the scene.
    glFlush();

    // Start the main loop.
    glutMainLoop();

    return 0;
}
