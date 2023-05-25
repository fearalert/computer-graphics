#include <GL/glut.h>
#include<iostream>
using namespace std;

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500, 500, -500, 500, -1, 1);
}

void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void ellipseMidPoint(GLint rx, GLint ry, GLint xc, GLint yc)
{

    // Region 1
    float x = 0;
    float y = ry;//(0,ry) ---
    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);

    // Slope Calculation
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    while (dx < dy)
    {
        //plotting (x,y)
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        if (p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + dx - dy + (ry * ry);
        }
    }
    // Region 2 1st Quadrant
    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);


    while (y > 0)
    {
        //plotting (x,y)
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        if (p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx);
            dx = dx + 2 * (ry * ry);
            p2 = p2 + dx - dy + (rx * rx);
        }
    }

}

void draw_axis()
{
    GLint i = -500;
    for (;i < 500;i++)
    {
        setPixel(i, 0);
        setPixel(0, i);
    }

}

void display()
{
    GLint rx = 300, ry = 150;//semi-Major axis & semi Minor Axis
    GLint xc = 0, yc = 0;//center of ellipse
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);

    draw_axis();

    ellipseMidPoint(rx, ry, xc, yc);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();

}