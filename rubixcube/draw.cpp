void draw()
{
    int i, j, flag = 0;
    float siz = 0.2, x, sp = .02;
    x = siz + sp;
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    if (rot)
    {
        ang += insp;
        if (ang > 90)
        {
            ang = 0;
            for (i = 0; i < 28; i++)
            {
                xro[i] = 0;
                yro[i] = 0;
                zro[i] = 0;
            }
            if (rot == 1)
                yrotation(layy, diry);
            if (rot == 2)
                xrotation(layx, dirx);
            if (rot == 3)
                zrotation(layz, dirz);
            if (rot == 9)
            {
                yrotation(1, -1);
                yrotation(2, -1);
                yrotation(3, -1);
            }
            if (rot == 11)
            {
                yrotation(1, 1);
                yrotation(2, 1);
                yrotation(3, 1);
            }
            if (rot == 14)
            {
                xrotation(1, -1);
                xrotation(2, -1);
                xrotation(3, -1);
            }
            if (rot == 16)
            {
                xrotation(1, 1);
                xrotation(2, 1);
                xrotation(3, 1);
            }

            rot = 0;
            yes = 1;
        }
    }
    rubic(siz, x);
    glColor3f(0, 0, 0);
    renderBitmapString(0.6, 1.1, GLUT_BITMAP_TIMES_ROMAN_24, "RESET");
    renderBitmapString(-0.9, 0.7, GLUT_BITMAP_TIMES_ROMAN_24, "SCRAMBLE");
    renderBitmapString(0.7, 0.4, GLUT_BITMAP_TIMES_ROMAN_24, "Project By:");
    renderBitmapString(0.7, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "Rohan Dhakal");

    // renderBitmapString(0.7, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, st);
    for (i = 0; i < 6; i++)
        for (j = 1; j < 10; j++)
        {
            if (C[i][5] != C[i][j])
            {
                flag = 1;

            }
        }
    if (!flag) {
        pressed = 0;
        solving = 0;
        renderBitmapString(-0.2, 0.5, GLUT_BITMAP_TIMES_ROMAN_24, "SOLVED");
    }
    glutSwapBuffers();
}
