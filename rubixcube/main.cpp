#include <iostream>

#include "include.h"
#include "mouse.cpp"
#include "allrotations.cpp"
#include "keyboard.cpp"
#include "cube.cpp"
#include "draw.cpp"

void wholr(int ax, int dir)
{
    int i;
    di = dir;
    for (i = 0; i < 28; i++)
    {
        if (ax)
            xro[i] = 1;
        else
            yro[i] = 1;
    }

    rot = 10 + 5 * ax + dir;
}

void anim(int t)
{
    glutPostRedisplay();
    glutTimerFunc(15, anim, 1);
}

void yfinal(int com)
{
    int i;
    diry = di = 2 * (com / 6) - 1;
    layy = (com - 1) % 3 + 1;

    for (i = 1; i < 10; i++)
        yro[(layy - 1) * 9 + i] = 1;
    rot = 1;
}

void xfinal(int com)
{
    dirx = di = 2 * (com / 6) - 1;
    layx = (com - 1) % 3 + 1;
    if (layx == 1)
    {
        xro[7] = 1;
        xro[8] = 1;
        xro[9] = 1;
        xro[16] = 1;
        xro[17] = 1;
        xro[18] = 1;
        xro[25] = 1;
        xro[26] = 1;
        xro[27] = 1;
    }
    if (layx == 2)
    {
        xro[4] = 1;
        xro[5] = 1;
        xro[6] = 1;
        xro[13] = 1;
        xro[14] = 1;
        xro[15] = 1;
        xro[22] = 1;
        xro[23] = 1;
        xro[24] = 1;
    }
    if (layx == 3)
    {
        xro[1] = 1;
        xro[2] = 1;
        xro[3] = 1;
        xro[10] = 1;
        xro[11] = 1;
        xro[12] = 1;
        xro[19] = 1;
        xro[20] = 1;
        xro[21] = 1;
    }

    rot = 2;
}

void zfinal(int com)
{
    dirz = -1 * (di = 2 * (com / 6) - 1);
    layz = (com - 1) % 3 + 1;
    if (layz == 1)
    {
        zro[9] = 1;
        zro[6] = 1;
        zro[3] = 1;
        zro[18] = 1;
        zro[15] = 1;
        zro[12] = 1;
        zro[21] = 1;
        zro[24] = 1;
        zro[27] = 1;
    }
    if (layz == 2)
    {
        zro[2] = 1;
        zro[5] = 1;
        zro[8] = 1;
        zro[11] = 1;
        zro[14] = 1;
        zro[17] = 1;
        zro[20] = 1;
        zro[23] = 1;
        zro[26] = 1;
    }
    if (layz == 3)
    {
        zro[1] = 1;
        zro[4] = 1;
        zro[7] = 1;
        zro[10] = 1;
        zro[13] = 1;
        zro[16] = 1;
        zro[19] = 1;
        zro[22] = 1;
        zro[25] = 1;
    }
    rot = 3;
}

int main(int argc, char** argv)
{
    int i, j;

    for (i = 0; i < 6; i++)
        for (j = 0; j < 10; j++)
            C[i][j] = i;
    for (i = 0; i < 28; i++)
    {
        xro[i] = 0;
        yro[i] = 0;
        zro[i] = 0;
    }
    std::cout << "MOVES: \n 1. For rotating the whole cube use special keys \n 2. layer Moves :\n\tX axis rotation : keys Q,W,E,R,T,Y\n\tY axis rotation : keys A,S,D,F,G,H\n\tZ axis rotation : keys Z,X,C,V,B,N\n\t\n\nFrequently used Rotations:\n\tR  : o\n\tR' : l\n\tU  : ;\n\tU' : j\n\tL  : j\n\tL' : u\n\tF  : p\n\tF' : i";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(660, 0);
    glutCreateWindow("RUBIK'S CUBE VISUALIZATION");


    glClearColor(0.5, 0.4, 0.7, 0.1);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyb);
    glutMouseFunc(mouse_click);
    glutTimerFunc(100, anim, 1);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}
