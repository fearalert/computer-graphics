#pragma once

#include<windows.h>
#include <GL/glut.h>

int C[6][10];
int xro[28], yro[28], zro[28];

int done = 0, di = 1, rot = 0, yes = 1, k = 0;
float ang = 0.0;
int dragging, unix, uniy, uniz, unif, clicked = 0;
int rotate_x = -25, rotate_y = 35;
int insp = 10;
int pressed = 0, solving = 0;
char st[8] = { '0',':','0','0',':','0','0','\0' };

void xrotation(int, int);
void yrotation(int, int);
void rmy(int, int, int, int, int);
void zrotation(int, int);
void rmz(int, int, int, int, int);
void fr(int);
void franti(int);
void yfinal(int);
void xfinal(int);
void zfinal(int);
void wholr(int, int);

void mouse_click(int, int, int, int);
void mouse_move(int, int);

int mpx, mpy, mpz;

int diry, layy, dirx, layx, dirz, layz;

void ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
}

void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}