#include "include.h"

void keyb(unsigned char key, int x, int y)
{
    pressed = 1;
    if (yes)
    {
        switch (key)
        {
        case 'q':xfinal(1); yes = 0; break;
        case 'w':xfinal(2); yes = 0; break;
        case 'e':xfinal(3); yes = 0; break;
        case 'r':xfinal(7); yes = 0; break;
        case 't':xfinal(8); yes = 0; break;
        case 'y':xfinal(9); yes = 0; break;
        case 'a':yfinal(1); yes = 0; break;
        case 's':yfinal(2); yes = 0; break;
        case 'd':yfinal(3); yes = 0; break;
        case 'f':yfinal(7); yes = 0; break;
        case 'g':yfinal(8); yes = 0; break;
        case 'h':yfinal(9); yes = 0; break;
        case 'z':zfinal(1); yes = 0; break;
        case 'x':zfinal(2); yes = 0; break;
        case 'c':zfinal(3); yes = 0; break;
        case 'v':zfinal(7); yes = 0; break;
        case 'b':zfinal(8); yes = 0; break;
        case 'n':zfinal(9); yes = 0; break;

        case 'o':xfinal(9); yes = 0; break;
        case 'l':xfinal(3); yes = 0; break;
        case 'k':yfinal(7); yes = 0; break;
        case ';':yfinal(1); yes = 0; break;
        case 'i':zfinal(7); yes = 0; break;
        case 'p':zfinal(1); yes = 0; break;
        case 'u':xfinal(7); yes = 0; break;
        case 'j':xfinal(1); yes = 0; break;

        default:break;
        }
    }
}

void specialKeys(int key, int x, int y)
{
    if (yes)
    {
        if (key == GLUT_KEY_RIGHT) {
            wholr(0, -1);
        }

        else if (key == GLUT_KEY_LEFT) {
            wholr(0, 1);
        }

        else if (key == GLUT_KEY_UP) {
            wholr(1, 1);
        }

        else if (key == GLUT_KEY_DOWN) {
            wholr(1, -1);
        }
    }
}
