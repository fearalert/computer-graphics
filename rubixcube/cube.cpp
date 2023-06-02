#include "include.h"


void setcol(int cc)
{
    switch (cc)
    {
    case 0:glColor3f(1.0, 1.0, 1.0); break;
    case 1:glColor3f(0.0, 0.0, 1.0); break;
    case 2:glColor3f(1.0, 1.0, 0.0); break;
    case 3:glColor3f(0.0, 1.0, 0.0); break;
    case 4:glColor3f(1.0, 0.0, 0.0); break;
    case 5:glColor3f(1.0, 0.5, 0.0); break;
    case 6:glColor3f(0.1, 0.0, 0.0); break;
    default:break;
    }
}

//___________________________________________________ ____(SINGLE) CUBE
void mycube(int pic, float siz, float x, float y, float z, int d, int f, int u, int b, int r, int l)
{
    siz /= 2;
    glPushMatrix();

    if (yro[pic])
        glRotatef(ang * di, 0.0, 1.0, 0.0);
    if (xro[pic])
        glRotatef(ang * di, 1.0, 0.0, 0.0);
    if (zro[pic])
        glRotatef(ang * di, 0.0, 0.0, 1.0);

    glTranslatef(x, y, z);

    glBegin(GL_POLYGON);
    setcol(d);
    glVertex3f(siz, -siz, siz);
    glVertex3f(siz, -siz, -siz);
    glVertex3f(-siz, -siz, -siz);
    glVertex3f(-siz, -siz, siz);
    glEnd();

    glBegin(GL_POLYGON);
    setcol(b);
    glVertex3f(siz, siz, siz);
    glVertex3f(siz, -siz, siz);
    glVertex3f(-siz, -siz, siz);
    glVertex3f(-siz, siz, siz);
    glEnd();

    glBegin(GL_POLYGON);
    setcol(u);
    glVertex3f(siz, siz, siz);
    glVertex3f(siz, siz, -siz);
    glVertex3f(-siz, siz, -siz);
    glVertex3f(-siz, siz, siz);
    glEnd();

    glBegin(GL_POLYGON);
    setcol(f);
    glVertex3f(siz, siz, -siz);
    glVertex3f(siz, -siz, -siz);
    glVertex3f(-siz, -siz, -siz);
    glVertex3f(-siz, siz, -siz);
    glEnd();

    glBegin(GL_POLYGON);
    setcol(r);
    glVertex3f(siz, siz, siz);
    glVertex3f(siz, -siz, siz);
    glVertex3f(siz, -siz, -siz);
    glVertex3f(siz, siz, -siz);
    glEnd();

    glBegin(GL_POLYGON);
    setcol(l);
    glVertex3f(-siz, siz, siz);
    glVertex3f(-siz, -siz, siz);
    glVertex3f(-siz, -siz, -siz);
    glVertex3f(-siz, siz, -siz);
    glEnd();

    glPopMatrix();
}
//_________________________________________________________RUBIK'S CUBE
void rubic(float siz, float x)
{
    mycube(1, siz, x, x, x, 6, 6, C[2][3], C[3][9], C[4][3], 6);
    mycube(2, siz, x, x, 0, 6, 6, C[2][6], 6, C[4][2], 6);
    mycube(3, siz, x, x, -x, 6, C[1][3], C[2][9], 6, C[4][1], 6);

    mycube(4, siz, 0, x, x, 6, 6, C[2][2], C[3][8], 6, 6);
    mycube(5, siz, 0, x, 0, 6, 6, C[2][5], 6, 6, 6);
    mycube(6, siz, 0, x, -x, 6, C[1][2], C[2][8], 6, 6, 6);

    mycube(7, siz, -x, x, x, 6, 6, C[2][1], C[3][7], 6, C[5][3]);
    mycube(8, siz, -x, x, 0, 6, 6, C[2][4], 6, 6, C[5][2]);
    mycube(9, siz, -x, x, -x, 6, C[1][1], C[2][7], 6, 6, C[5][1]);
    //_____MIDDLE_LAYER
    mycube(10, siz, x, 0, x, 6, 6, 6, C[3][6], C[4][6], 6);
    mycube(11, siz, x, 0, 0, 6, 6, 6, 6, C[4][5], 6);
    mycube(12, siz, x, 0, -x, 6, C[1][6], 6, 6, C[4][4], 6);

    mycube(13, siz, 0, 0, x, 6, 6, 6, C[3][5], 6, 6);
    //mycube(2,siz, 0, 0, 0,6       ,6      ,6      ,6      ,6      ,6);
    mycube(15, siz, 0, 0, -x, 6, C[1][5], 6, 6, 6, 6);

    mycube(16, siz, -x, 0, x, 6, 6, 6, C[3][4], 6, C[5][6]);
    mycube(17, siz, -x, 0, 0, 6, 6, 6, 6, 6, C[5][5]);
    mycube(18, siz, -x, 0, -x, 6, C[1][4], 6, 6, 6, C[5][4]);
    //_________BOTTOM LATER____
    mycube(19, siz, x, -x, x, C[0][9], 6, 6, C[3][3], C[4][9], 6);
    mycube(20, siz, x, -x, 0, C[0][6], 6, 6, 6, C[4][8], 6);
    mycube(21, siz, x, -x, -x, C[0][3], C[1][9], 6, 6, C[4][7], 6);

    mycube(22, siz, 0, -x, x, C[0][8], 6, 6, C[3][2], 6, 6);
    mycube(23, siz, 0, -x, 0, C[0][5], 6, 6, 6, 6, 6);
    mycube(24, siz, 0, -x, -x, C[0][2], C[1][8], 6, 6, 6, 6);

    mycube(25, siz, -x, -x, x, C[0][7], 6, 6, C[3][1], 6, C[5][9]);
    mycube(26, siz, -x, -x, 0, C[0][4], 6, 6, 6, 6, C[5][8]);
    mycube(27, siz, -x, -x, -x, C[0][1], C[1][7], 6, 6, 6, C[5][7]);
}
