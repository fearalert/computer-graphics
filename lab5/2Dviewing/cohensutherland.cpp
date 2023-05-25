#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>

GLfloat xMin = -0.4f, xMax = 0.0f, yMin = -0.4f, yMax = 0.5f;
GLfloat xc1 = -0.9, yc1 = -0.2, xc2 = 0.7, yc2 = 0.4;

GLint Left = 1, Right = 2, Bot = 4, Top = 8;
GLint C1, C2;
GLint Clip_Flag = 0, Flag = 1;;


int Get_Code(GLfloat x, GLfloat y)
{
    int Code = 0;
    if (x < xMin)
        Code = Code | Left;
    if (x > xMax)
        Code = Code | Right;
    if (y < yMin)
        Code = Code | Bot;
    if (y > yMax)
        Code = Code | Top;
    return Code;
}

void Clip()
{
    int C;
    GLfloat x, y;
    if (C1)
        C = C1;
    else
        C = C2;

    if (C & Left)
    {
        x = xMin;
        y = yc1 + (yc2 - yc1) * ((xMin - xc1) / (xc2 - xc1));
    }
    if (C & Right)
    {
        x = xMax;
        y = yc1 + (yc2 - yc1) * ((xMax - xc1) / (xc2 - xc1));
    }
    if (C & Bot)
    {
        y = yMin;
        x = xc1 + (xc2 - xc1) * ((yMin - yc1) / (yc2 - yc1));
    }
    if (C & Top)
    {
        y = yMax;
        x = xc1 + (xc2 - xc1) * ((yMax - yc1) / (yc2 - yc1));
    }

    if (C == C1)
    {
        xc1 = x;
        yc1 = y;
    }
    else
    {
        xc2 = x;
        yc2 = y;
    }
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(xMin, yMin);
    glVertex2f(xMax, yMin);
    glVertex2f(xMax, yMax);
    glVertex2f(xMin, yMax);
    glEnd();

    glColor3f(1.0f, 0.0f, 1.0f);
    if (Flag == 1)
    {
        glBegin(GL_LINES);
        glVertex2f(xc1, yc1);
        glVertex2f(xc2, yc2);
        glEnd();
    }

    while (1 & Clip_Flag == 1)
    {
        C1 = Get_Code(xc1, yc1);
        C2 = Get_Code(xc2, yc2);

        if ((C1 | C2) == 0)
            break;
        else if ((C1 & C2) != 0)
        {
            Flag = 0;
            break;
        }
        else
            Clip();
    }
    glFlush();
}

void Keyboard(unsigned char ch, int x, int y)
{
    Clip_Flag = 1;
    glutPostRedisplay();
}

int main(int argC, char* argV[])
{
    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Cohen-Sutherland Algorithm");
    glutDisplayFunc(Draw);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return 0;
}