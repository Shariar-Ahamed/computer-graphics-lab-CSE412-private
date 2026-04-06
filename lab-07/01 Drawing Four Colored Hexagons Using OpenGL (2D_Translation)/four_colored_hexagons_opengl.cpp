#include <GL/glut.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
}

void drawHexagon()
{
    glBegin(GL_POLYGON);

    glVertex2f(0, 40);
    glVertex2f(30, 20);
    glVertex2f(30, -20);
    glVertex2f(0, -40);
    glVertex2f(-30, -20);
    glVertex2f(-30, 20);

    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Top Left (Red)
    glPushMatrix();
    glTranslatef(-70, 70, 0);
    glColor3f(1, 0, 0);
    drawHexagon();
    glPopMatrix();

    // Top Right (Blue)
    glPushMatrix();
    glTranslatef(70, 70, 0);
    glColor3f(0, 0, 1);
    drawHexagon();
    glPopMatrix();

    // Bottom Left (Green)
    glPushMatrix();
    glTranslatef(-70, -70, 0);
    glColor3f(0, 1, 0);
    drawHexagon();
    glPopMatrix();

    // Bottom Right (Yellow)
    glPushMatrix();
    glTranslatef(70, -70, 0);
    glColor3f(1, 1, 0);
    drawHexagon();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("4 Colored Hexagons");

    init();
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}