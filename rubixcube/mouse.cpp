#include "include.h"
#include "scramble.cpp"

void mouse_click(int button, int state, int x, int y)
{
    float fux, fuy, fax, fay;
    int nf[6], i, j;
    nf[3] = 0;
    nf[4] = 0;
    nf[5] = 0;
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_UP) {
            if (x > 92 && x < 217 && y>33 && y < 53)
            {
                scramble(x);
                solving = 1;
                pressed = 0;
                // tmi = 0; tm = 0; tse = 0;

            }
            if (x > 519 && x < 596 && y>33 && y < 53)
            {
                pressed = 0;
                solving = 0;
                for (i = 0; i < 6; i++)
                    for (j = 0; j < 10; j++)
                        C[i][j] = i;
                for (i = 0; i < 28; i++)
                {
                    xro[i] = 0;
                    yro[i] = 0;
                    zro[i] = 0;
                }
                // tmi = 0; tm = 0; tse = 0;
            }
        }

        if (state == GLUT_DOWN)
        {
            dragging = 1;


            if (x > 192 && x < 507)
            {
                unix = x - 192;
                if (unix / 62 < 3) {
                    nf[0] = 4;
                    unix = unix / 62;
                }
                else
                {
                    nf[0] = 1;
                    unix -= 186;
                    unix = 3 + unix / 43;
                }

                fux = x - 195;
                fuy = y - 261;
                fux = fux + 1.63 * fuy;
                if (fux > 0 && fux < 600)
                {

                    if (fux < 270) {
                        nf[1] = 4;
                        uniy = fux / 90;
                    }
                    else {
                        nf[1] = 2;
                        uniy = 3 + (fux - 270) / 110;
                    }

                    fax = x - 322;
                    fay = y - 183;
                    fax = 3.31 * fay - fax;
                    if (fax > 0 && fax < 1050)
                    {
                        if (fax < 381) {
                            nf[2] = 1;
                            uniz = fax / 127;
                        }
                        else {
                            nf[2] = 2;
                            uniz = 3 + (fax - 381) / 223;
                        }
                        for (i = 0; i < 3; i++)
                        {
                            if (nf[i] == 1)nf[3] = 1;
                            if (nf[i] == 2)nf[4] = 1;
                            if (nf[i] == 4)nf[5] = 1;
                        }
                        if (nf[3] == 0)unif = 1;
                        if (nf[4] == 0)unif = 2;
                        if (nf[5] == 0)unif = 4;
                        clicked = 1;
                        //printf("%d %d %d %d\n",unix,uniy,uniz,unif);
                        //allocm(f,unix,uniy,uniz);
                    }
                }
            }
            //printf("%d %d \n",x,y);
        }
        else
            dragging = 0;
    }
}