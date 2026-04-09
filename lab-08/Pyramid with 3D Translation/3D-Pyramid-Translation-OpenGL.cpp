#include <GL/glut.h>
#include <iostream>
using namespace std;

// Base square points
float X1, Y1, Z1;
float X2, Y2, Z2;

// Top point
float TXp, TYp, TZp;

// Translation unit
float Tx, Ty, Tz;

// Movement
float moveX = 0, moveY = 0, moveZ = 0;

// ================= PYRAMID =================
void drawPyramidFromPoints(float x1, float y1, float z1,
                           float x2, float y2, float z2,
                           float txp, float typ, float tzp)
{
    // Bottom square
    glBegin(GL_QUADS);

    glColor3f(1, 1, 0); // Yellow
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);

    glEnd();

    // 4 triangle faces
    glBegin(GL_TRIANGLES);

    // Front
    glColor3f(1, 0, 0);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(txp, typ, tzp);

    // Right
    glColor3f(0, 1, 0);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glVertex3f(txp, typ, tzp);

    // Back
    glColor3f(0, 0, 1);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);
    glVertex3f(txp, typ, tzp);

    // Left
    glColor3f(1, 0, 1);
    glVertex3f(x1, y1, z2);
    glVertex3f(x1, y1, z1);
    glVertex3f(txp, typ, tzp);

    glEnd();
}

// ================= DISPLAY =================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(15, 15, 25, 0, 0, 0, 0, 1, 0);

    // Apply translation (same as your cube code)
    glTranslatef(moveX, moveY, moveZ);

    drawPyramidFromPoints(X1, Y1, Z1, X2, Y2, Z2, TXp, TYp, TZp);

    glutSwapBuffers();
}

// ================= KEYBOARD =================
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'X': moveX += Tx; break;
    case 'x': moveX -= Tx; break;

    case 'Y': moveY += Ty; break;
    case 'y': moveY -= Ty; break;

    case 'Z': moveZ += Tz; break;
    case 'z': moveZ -= Tz; break;
    }

    glutPostRedisplay();
}

// ================= INIT =================
void init()
{
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// ================= MAIN =================
int main(int argc, char** argv)
{
    cout << "Enter base first point (x1 y1 z1): ";
    cin >> X1 >> Y1 >> Z1;

    cout << "Enter base opposite point (x2 y2 z2): ";
    cin >> X2 >> Y2 >> Z2;

    cout << "Enter top point (x y z): ";
    cin >> TXp >> TYp >> TZp;

    cout << "Enter translation unit (Tx Ty Tz): ";
    cin >> Tx >> Ty >> Tz;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Pyramid Translation");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
