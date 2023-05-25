#include <iostream>
#include <GL/glut.h>

using namespace std;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 250, 0, 250);
}

void bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x, y, p;

    if (dy <= dx)
    {
        if (x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        x = x1;
        y = y1;
        p = 2 * dy - dx;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (x < x2)
        {
            x++;
            if (p < 0)
                p += 2 * dy;
            else
            {
                y++;
                p += 2 * (dy - dx);
            }
            glVertex2i(x, y);
        }
        glEnd();
    }
    else
    {
        if (y1 > y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        x = x1;
        y = y1;
        p = 2 * dx - dy;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        while (y < y2)
        {
            y++;
            if (p < 0)
                p += 2 * dx;
            else
            {
                x++;
                p += 2 * (dx - dy);
            }
            glVertex2i(x, y);
        }
        glEnd();
    }
}

void display()
{
    GLint x1 = 110, y1 = 120;
    GLint x2 = 200, y2 = 24;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    bresenham(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}