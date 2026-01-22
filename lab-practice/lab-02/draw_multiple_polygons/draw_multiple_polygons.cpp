#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* ===== Left Star (Red) ===== */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6,  0.0);
    glVertex2f(-0.6,  0.6);
    glVertex2f(-0.35, 0.15);
    glVertex2f( 0.0,  0.0);
    glVertex2f(-0.35,-0.15);
    glVertex2f(-0.6, -0.6);
    glVertex2f(-0.85,-0.15);
    glVertex2f(-1.2,  0.0);
    glVertex2f(-0.85, 0.15);
    glVertex2f(-0.6,  0.6);
    glEnd();

    /* ===== Top Star (Green) ===== */
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0,  0.6);
    glVertex2f(0.0,  1.2);
    glVertex2f(0.25, 0.75);
    glVertex2f(0.6,  0.6);
    glVertex2f(0.25, 0.45);
    glVertex2f(0.0,  0.0);
    glVertex2f(-0.25,0.45);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.25,0.75);
    glVertex2f(0.0,  1.2);
    glEnd();

    /* ===== Right Star (White) ===== */
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.6,  0.0);
    glVertex2f(0.6,  0.6);
    glVertex2f(0.85, 0.15);
    glVertex2f(1.2,  0.0);
    glVertex2f(0.85,-0.15);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.35,-0.15);
    glVertex2f(0.0,  0.0);
    glVertex2f(0.35, 0.15);
    glVertex2f(0.6,  0.6);
    glEnd();

    /* ===== Bottom Star (Blue) ===== */
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, -0.6);
    glVertex2f(0.0,  0.0);
    glVertex2f(0.25,-0.45);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.25,-0.75);
    glVertex2f(0.0, -1.2);
    glVertex2f(-0.25,-0.75);
    glVertex2f(-0.6, -0.6);
    glVertex2f(-0.25,-0.45);
    glVertex2f(0.0,  0.0);
    glEnd();

    glFlush();
}

void init()
{

    glClearColor(0.6, 0.8, 1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,300);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("OpenGL Small Point");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}