#include <iostream>
#include <cmath>
#include <GL/glut.h>

#define PI 3.14159265358979323846
int mousedown = 0;
GLfloat vertices[][3] = {
    {-1.0, -1.0, 1.0},  // 0: Bottom-left-front
    {1.0, -1.0, 1.0},   // 1: Bottom-right-front
    {1.0, 1.0, 1.0},    // 2: Top-right-front
    {-1.0, 1.0, 1.0},   // 3: Top-left-front
    {-1.0, -1.0, -1.0}, // 4: Bottom-left-back
    {1.0, -1.0, -1.0},  // 5: Bottom-right-back
    {1.0, 1.0, -1.0},   // 6: Top-right-back
    {-1.0, 1.0, -1.0}   // 7: Top-left-back
};

GLint faces[][4] = {
    {0, 1, 2, 3}, // Front face
    {1, 5, 6, 2}, // Right face
    {4, 5, 6, 7}, // Back face
    {0, 4, 7, 3}, // Left face
    {0, 1, 5, 4}, // Bottom face
    {3, 2, 6, 7}  // Top face
};

GLfloat colors[][3] = {
      {1.0, 0.0, 0.0}, // Red
      {0.0, 1.0, 0.0}, // Green
      {0.0, 0.0, 1.0}, // Blue
      {1.0, 1.0, 0.0}, // Yellow
      {1.0, 0.0, 1.0}, // Magenta
      {0.0, 1.0, 1.0}  // Cyan
};


void multiplyMatrixByVector(GLfloat matrix[], GLfloat vector[], GLfloat result[]) {
    for (int i = 0; i < 4; i++) {
        result[i] = 0.0f;
        for (int j = 0; j < 4; j++) {
            result[i] += matrix[i * 4 + j] * vector[j];
        }
    }
}

void multiply(GLfloat matrix[]) {
    for (int i = 0; i < 8; i++) {
        GLfloat vertex[] = { vertices[i][0], vertices[i][1], vertices[i][2], 1.0f };
        GLfloat result[4];

        multiplyMatrixByVector(matrix, vertex, result);

        vertices[i][0] = result[0];
        vertices[i][1] = result[1];
        vertices[i][2] = result[2];
    }
}

void rotateCubeAlongXAxis(GLfloat angle) {
    GLfloat rotationMatrixX[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cosf(angle), -sinf(angle), 0.0f,
        0.0f, sinf(angle), cosf(angle), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(rotationMatrixX);
}

void rotateCubeAlongYAxis(GLfloat angle) {
    GLfloat rotationMatrixY[] = {
        cosf(angle), 0.0f, sinf(angle), 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -sinf(angle), 0.0f, cosf(angle), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(rotationMatrixY);
}

void rotateCubeAlongZAxis(GLfloat angle) {
    GLfloat rotationMatrixZ[] = {
        cosf(angle), -sinf(angle), 0.0f, 0.0f,
        sinf(angle), cosf(angle), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(rotationMatrixZ);
}


void scaleCubeAlongXAxis(GLfloat scale) {
    GLfloat scalingMatrixX[] = {
        scale, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(scalingMatrixX);
}

void scaleCubeAlongYAxis(GLfloat scale) {
    GLfloat scalingMatrixY[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, scale, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(scalingMatrixY);
}

void scaleCubeAlongZAxis(GLfloat scale) {
    GLfloat scalingMatrixZ[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, scale, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(scalingMatrixZ);
}


void translateCubeAlongXAxis(GLfloat translation) {
    GLfloat translationMatrixX[] = {
        1.0f, 0.0f, 0.0f, translation,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(translationMatrixX);

}

void translateCubeAlongYAxis(GLfloat translation) {
    GLfloat translationMatrixY[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, translation,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(translationMatrixY);

}

void translateCubeAlongZAxis(GLfloat translation) {
    GLfloat translationMatrixZ[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, translation,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    multiply(translationMatrixZ);
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 10.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawCube() {
    for (int i = 0; i < 6; i++) {
        glBegin(GL_QUADS);
        glColor3fv(colors[i]); // Red color
        for (int j = 0; j < 4; j++) {
            glVertex3fv(vertices[faces[i][j]]);
        }
        glEnd();
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 5.0,  // Eye position
        0.0, 0.0, 0.0,  // Look-at position
        0.0, 1.0, 0.0); // Up direction

    drawCube();

    glFlush();
    glutSwapBuffers();
}

void resize(int w, int h)
{
    float grow_shrink = 70.0f;
    float resize_f = 1.0f;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(grow_shrink, resize_f * w / h, resize_f, 100 * resize_f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(1);
        break;
    case 'x':
        rotateCubeAlongXAxis(-45.0f);
        break;
    case 'X':
        rotateCubeAlongXAxis(45.0f);
        break;
    case 'y':
        rotateCubeAlongYAxis(-45.0f);
        break;
    case 'Y':
        rotateCubeAlongYAxis(45.0f);
        break;
    case 'z':
        rotateCubeAlongZAxis(-45.0f);
        break;
    case 'Z':
        rotateCubeAlongZAxis(45.0f);
        break;
    case '1':
        scaleCubeAlongXAxis(1.2f);
        break;
    case '2':
        scaleCubeAlongYAxis(1.2f);
        break;
    case '3':
        scaleCubeAlongZAxis(1.2f);
        break;
    case '4':
        scaleCubeAlongXAxis(0.12f);
        break;
    case '5':
        scaleCubeAlongYAxis(0.12f);
        break;
    case '6':
        scaleCubeAlongZAxis(0.12f);
        break;
    case 'q':
    case 'Q':
        translateCubeAlongXAxis(0.12f);
        break;
    case 'w':
    case 'W':
        translateCubeAlongYAxis(0.12f);
        break;
    case 'e':
    case 'E':
        translateCubeAlongZAxis(0.12f);
        break;
    case 'a':
    case 'A':
        translateCubeAlongXAxis(-0.12f);
        break;
    case 's':
    case 'S':
        translateCubeAlongYAxis(-0.12f);
        break;
    case 'd':
    case 'D':
        translateCubeAlongZAxis(-0.12f);
        break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mousedown = 1;
    }
    else
        mousedown = 0;
}

void mouseMotion(int x, int y)
{
    if (mousedown)
    {
        rotateCubeAlongXAxis(20.f);
        rotateCubeAlongYAxis(20.f);
        rotateCubeAlongZAxis(20.f);

        glutPostRedisplay();
    }
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cube 3D Transformation");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
