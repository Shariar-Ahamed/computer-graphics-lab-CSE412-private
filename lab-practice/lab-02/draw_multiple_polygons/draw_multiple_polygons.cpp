#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,8);
        glVertex2f(2,2);
        glVertex2f(8,0);
        glVertex2f(2,-2);
        glVertex2f(0,-8);
        glVertex2f(-2,-2);
        glVertex2f(-8,0);
        glVertex2f(-2,2);
        glVertex2f(0,8);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(8,8);
        glVertex2f(8,16);
        glVertex2f(10,10);
        glVertex2f(16,8);
        glVertex2f(10,6);
        glVertex2f(8,0);
        glVertex2f(6,6);
        glVertex2f(0,8);
        glVertex2f(6,10);
        glVertex2f(8,16);
    glEnd();


    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(16,0);
        glVertex2f(16,8);
        glVertex2f(18,2);
        glVertex2f(24,0);
        glVertex2f(18,-2);
        glVertex2f(16,-8);
        glVertex2f(14,-2);
        glVertex2f(8,0);
        glVertex2f(14,2);
        glVertex2f(16,8);
    glEnd();


    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(8,-8);
        glVertex2f(8,0);
        glVertex2f(10,-6);
        glVertex2f(16,-8);
        glVertex2f(10,-10);
        glVertex2f(8,-16);
        glVertex2f(6,-10);
        glVertex2f(0,-8);
        glVertex2f(6,-6);
        glVertex2f(8,0);
    glEnd();

    glFlush();
}


void init()
{
    glClearColor(0.6, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100.0, 100.0,
               -100.0, 100.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("OpenGL POLYGON Project");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}