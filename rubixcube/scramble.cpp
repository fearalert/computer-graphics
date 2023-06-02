#include "include.h"

void scramble(int x)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        switch ((rand() + x) % 20)
        {
        case 1:xrotation(3, -1); break;
        case 2:xrotation(2, -1); break;
        case 3:xrotation(1, -1); break;
        case 4:xrotation(1, 1); break;
        case 5:xrotation(3, 1); break;
        case 6:xrotation(2, 1); break;
        case 7:yrotation(3, -1); break;
        case 8:yrotation(2, -1); break;
        case 9:yrotation(1, -1); break;
        case 10:yrotation(1, 1); break;
        case 11:yrotation(3, 1); break;
        case 12:yrotation(2, 1); break;
        case 13:zrotation(3, -1); break;
        case 14:zrotation(2, -1); break;
        case 15:zrotation(1, -1); break;
        case 16:zrotation(1, 1); break;
        case 17:zrotation(3, 1); break;
        case 18:zrotation(2, 1); break;

        default:break;
        }
    }
}