#include <iostream>
#include <GL/glut.h>

using namespace std;

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 250, 0, 250);
}

void DDA(int x1, int y1, int x2, int y2)
{
    int steps;

    float dx = x2 - x1;
    float dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i < steps; i++)
    {
        glVertex2i(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

void display()
{
    GLint x1 = 110, y1 = 120;
    GLint x2 = 200, y2 = 24;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    DDA(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}