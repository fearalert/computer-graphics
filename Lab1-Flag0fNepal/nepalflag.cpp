#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14

void nepalFlag() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(-4, 4, -4, 4, -4, 4);
    glClear(GL_COLOR_BUFFER_BIT);


    // Draw the triangle using red color
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(1, 12);
    glVertex2f(10, 0.5);
    glVertex2f(1, 0.5);

    glEnd();

    // Draw the semi circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    float x, y;
    float radius = 2;
    float center_x = 4, center_y = 4;
    glVertex2f(center_x, center_y);
    for (int i = 90; i <= 270; i++)
    {
        x = center_x + radius * sin(i * PI / 180.0);
        y = center_y + radius * cos(i * PI / 180.0);
        glVertex2f(x, y);
    }
    glEnd();

    const float DegToRad = PI / 180;

    // Draw the Star over semi circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    int count = 1;
    glVertex2f(center_x + 0.2, center_y + 0.2);
    for (int i = 0; i <= 360; i += 360 / 24) {
        float DegInRad = i * DegToRad;
        if (count % 2 != 0)
            glVertex2f(center_x + cos(DegInRad) * 1.5, center_y + 0.2 + sin(DegInRad) * 1.5);
        else
            glVertex2f((center_x + cos(DegInRad) * 1.5 / 2), (center_y + 0.2 + sin(DegInRad) * 1.5 / 2));
        count++;
    }

    glEnd();

    // Draw the quadrilateral using red color
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1, 1);
    glVertex2f(4.5, 0.5);
    glVertex2f(10, -11);
    glVertex2f(1, -11);
    glEnd();

    float center_x1 = 4, center_y1 = -7;

    // Draw the star on the quad
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(center_x1, center_y1);
    for (int i = 0; i <= 360; i += 360 / 24) {
        float DegInRad = i * DegToRad;
        if (count % 2 != 0)
            glVertex2f(center_x1 + cos(DegInRad) * 2, center_y1 + sin(DegInRad) * 2);
        else
            glVertex2f((center_x1 + cos(DegInRad) * 2 / 2), (center_y1 + sin(DegInRad) * 2 / 2));
        count++;
    }

    glEnd();

    // Draw the outline of Nepal Map
    glLineWidth((GLfloat)18.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(1, -13);
    glVertex2f(1, 12.1);
    glVertex2f(1, 12);
    glVertex2f(10, 0.5);
    glVertex2f(10, 0.5);
    glVertex2f(4.5, 0.5);
    glVertex2f(4.5, 0.5);
    glVertex2f(10, -11);
    glVertex2f(10, -11.1);
    glVertex2f(1, -11);

    glEnd();



    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Flag of Nepal");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(nepalFlag);
    glutMainLoop();

    return 0;
}