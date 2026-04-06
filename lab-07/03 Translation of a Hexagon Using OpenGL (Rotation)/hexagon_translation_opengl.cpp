#include <GL/glut.h>
#include <GL/gl.h>

float tx = 0.0;
float ty = 0.0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void drawHexagon()
{
    // Only Filled Hexagon (No Border)
    glColor3f(1, 0, 0);
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

    glPushMatrix();
    glTranslatef(tx, ty, 0);

    drawHexagon();

    glPopMatrix();

    glutSwapBuffers();
}

void spe_key(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            ty += 5;
            break;

        case GLUT_KEY_DOWN:
            ty -= 5;
            break;

        case GLUT_KEY_RIGHT:
            tx += 5;
            break;

        case GLUT_KEY_LEFT:
            tx -= 5;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hexagon Filled Only");

    init();
    glutDisplayFunc(Draw);
    glutSpecialFunc(spe_key);

    glutMainLoop();
    return 0;
}