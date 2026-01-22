#include<GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,2.0);
    glVertex2f(2.0,2.0);
    glVertex2f(2.0,0.0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glPointSize(5.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,2.0);
    glVertex2f(1,3);
    glVertex2f(2.0,2.0);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.6,0.8,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(200,300);
    glutCreateWindow("OpenGL Small Point");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}