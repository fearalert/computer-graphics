#include "include.h"

void xrotation(int lay, int dir) { //lay can be 1,2,3;dir can be -1 or 1
    int i, j, temp, te1, te2, te3;
    if (dir == -1)
    {
        temp = lay;
        te1 = C[0][lay];
        te2 = C[0][lay + 3];
        te3 = C[0][lay + 6];
        for (j = 1; j < 4; j++)
            for (i = 0, lay = temp; i < 3; i++, lay += 3)
                C[j - 1][lay] = C[j][lay];
        lay = temp;
        C[3][lay] = te1;
        C[3][lay + 3] = te2;
        C[3][lay + 6] = te3;
        if (temp == 3)
            franti(4);
        if (temp == 1)
            franti(5);

    }
    else
    {
        temp = lay;
        te1 = C[3][lay];
        te2 = C[3][lay + 3];
        te3 = C[3][lay + 6];
        for (j = 3; j > 0; j--)
            for (i = 0, lay = temp; i < 3; i++, lay += 3)
                C[j][lay] = C[j - 1][lay];
        lay = temp;
        C[0][lay] = te1;
        C[0][lay + 3] = te2;
        C[0][lay + 6] = te3;
        if (temp == 3)
            fr(4);
        if (temp == 1)
            fr(5);
    }
}
void yrotation(int lay, int dir)
{
    if (lay == 1)
    {
        rmy(1, 3, 9, 1, dir);
        rmy(2, 2, 8, 2, dir);
        rmy(3, 1, 7, 3, dir);
        if (dir == 1)
            fr(2);
        if (dir == -1)
            franti(2);
    }
    if (lay == 2)
    {
        rmy(4, 6, 6, 4, dir);
        rmy(5, 5, 5, 5, dir);
        rmy(6, 4, 4, 6, dir);
    }
    if (lay == 3)
    {
        rmy(7, 9, 3, 7, dir);
        rmy(8, 8, 2, 8, dir);
        rmy(9, 7, 1, 9, dir);
        if (dir == 1)
            franti(0);
        else
            fr(0);
    }
}
void rmy(int fr, int le, int ba, int ri, int dir)
{
    int te;
    if (dir == 1)
    {
        te = C[4][ri];
        C[4][ri] = C[3][ba];
        C[3][ba] = C[5][le];
        C[5][le] = C[1][fr];
        C[1][fr] = te;
    }
    else
    {
        te = C[4][ri];
        C[4][ri] = C[1][fr];
        C[1][fr] = C[5][le];
        C[5][le] = C[3][ba];
        C[3][ba] = te;

    }
}
void zrotation(int lay, int dir)
{
    if (lay == 1)
    {
        rmz(7, 1, 3, 7, dir);
        rmz(8, 4, 2, 4, dir);
        rmz(9, 7, 1, 1, dir);
        if (dir == 1)
            fr(1);
        else
            franti(1);
    }
    if (lay == 2)
    {
        rmz(4, 2, 6, 8, dir);
        rmz(5, 5, 5, 5, dir);
        rmz(6, 8, 4, 2, dir);
    }
    if (lay == 3)
    {
        rmz(1, 3, 9, 9, dir);
        rmz(2, 6, 8, 6, dir);
        rmz(3, 9, 7, 3, dir);
        if (dir == 1)
            franti(3);
        else
            fr(3);
    }
}
void rmz(int up, int ri, int dw, int le, int dir)
{
    int te;
    if (dir == 1)
    {
        te = C[4][ri];
        C[4][ri] = C[2][up];
        C[2][up] = C[5][le];
        C[5][le] = C[0][dw];
        C[0][dw] = te;
    }
    else
    {
        te = C[4][ri];
        C[4][ri] = C[0][dw];
        C[0][dw] = C[5][le];
        C[5][le] = C[2][up];
        C[2][up] = te;

    }
}
void fr(int face)
{
    int temp;
    temp = C[face][2];
    C[face][2] = C[face][4];
    C[face][4] = C[face][8];
    C[face][8] = C[face][6];
    C[face][6] = temp;
    temp = C[face][1];
    C[face][1] = C[face][7];
    C[face][7] = C[face][9];
    C[face][9] = C[face][3];
    C[face][3] = temp;
}
void franti(int face)
{
    int temp;
    temp = C[face][2];
    C[face][2] = C[face][6];
    C[face][6] = C[face][8];
    C[face][8] = C[face][4];
    C[face][4] = temp;
    temp = C[face][1];
    C[face][1] = C[face][3];
    C[face][3] = C[face][9];
    C[face][9] = C[face][7];
    C[face][7] = temp;
}