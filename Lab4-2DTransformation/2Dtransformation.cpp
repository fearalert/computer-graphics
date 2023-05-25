#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

GLfloat triangle[3][2] = { { -0.5, 0.0 }, { 0.5, 0.0 }, { 0.0, 0.5 } }; // Coordinates of the triangle
// Define angle
GLfloat angle = 45.0;
GLfloat degToRadian = angle * PI / 180;
// Define the translation parameters
GLfloat tx = 0.0, ty = 0.0;
// Define scaling factor
GLfloat sx = 0.0, sy = 0.0;
// rotation matrix
GLfloat rotationMatrix[2][2] = { { cos(degToRadian), -sin(degToRadian) }, { sin(degToRadian), cos(degToRadian) } };
// Reflection matrix
GLfloat reflectionMatrix[2][2] = { { 1, 0 }, { 0, -1 } };
// Shearing matrix
GLfloat shearingMatrix[3][3] = { { 1, 0.5, 0 }, { 0.5, 1, 0 }, { 0, 0, 1 } };

void reflection_matrix() {
    for (GLint i = 0; i < 3; i++) {
        GLfloat x = triangle[i][0];
        GLfloat y = triangle[i][1];
        triangle[i][0] = x * reflectionMatrix[0][0] + y * reflectionMatrix[0][1];
        triangle[i][1] = x * reflectionMatrix[1][0] + y * reflectionMatrix[1][1];
    }
}

void draw_reflected_triangle() {
    reflection_matrix();
    // Draw the reflected triangle
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();
}

void rotation_matrix() {
    for (GLint i = 0; i < 3; i++) {
        GLfloat x = triangle[i][0];
        GLfloat y = triangle[i][1];
        triangle[i][0] = x * rotationMatrix[0][0] + y * rotationMatrix[0][1];
        triangle[i][1] = x * rotationMatrix[1][0] + y * rotationMatrix[1][1];
    }
}

void draw_rotated_triangle() {
    rotation_matrix();
    // Draw the rotated triangle
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();
}

void translate(GLfloat tx, GLfloat ty) {
    // Translate the triangle by (tx, ty)
    for (GLint i = 0; i < 3; i++) {
        triangle[i][0] += tx;
        triangle[i][1] += ty;
    }
}

void draw_translated_triangle(GLfloat tx, GLfloat ty) {
    translate(tx, ty);
    // Draw the translated triangle
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();
}


void draw_scaled_triangle(GLfloat sx, GLfloat sy) {
    // Apply scaling factors to each vertex of the triangle
    for (int i = 0; i < 3; i++) {
        triangle[i][0] *= sx;
        triangle[i][1] *= sy;
    }

    // Draw the scaled triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();
}

void shearing_matrix() {
    // Apply shearing matrix to each vertex of the triangle
    for (GLint i = 0; i < 3; i++) {
        GLfloat x = triangle[i][0];
        GLfloat y = triangle[i][1];
        GLfloat w = triangle[i][2];
        triangle[i][0] = x * shearingMatrix[0][0] + y * shearingMatrix[0][1] + w * shearingMatrix[0][2];
        triangle[i][1] = x * shearingMatrix[1][0] + y * shearingMatrix[1][1] + w * shearingMatrix[1][2];
        triangle[i][2] = x * shearingMatrix[2][0] + y * shearingMatrix[2][1] + w * shearingMatrix[2][2];
    }
}

void draw_sheared_triangle() {
    shearing_matrix();
    // Draw the sheared triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0] / triangle[i][2], triangle[i][1] / triangle[i][2]);
    }
    glEnd();

}

void draw_triangle() {
    // Draw the triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color

    glLoadIdentity(); // Reset transformation matrix to identity matrix

    draw_triangle();
    glutSwapBuffers(); // Render the graphics
}

void keyboard_func(unsigned char key, GLint x, GLint y)
{
    switch (key)
    {
    case 't':
        tx += 0.15;
        ty += 0.15;
        draw_translated_triangle(tx, ty);
        break;
    case 'r':
        draw_reflected_triangle();
        break;
    case 'R':
        draw_rotated_triangle();
        break;
    case 's':
        sx = 1.5;
        sy = 1.5;
        draw_scaled_triangle(sx, sy);
        break;
    case 'S':
        draw_sheared_triangle();
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Translation/Reflection/Rotation/Scaling/Shearing of Triangle");
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background color
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard_func);
    glutMainLoop();
    return 0;
}
