#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

// Original Hexagon coordinates
float x[6] = {100, 150, 150, 100, 50, 50};
float y[6] = {150, 120, 80, 50, 80, 120};

// Scaling factors
float sx, sy;

// Scaled coordinates
float sx_h[6], sy_h[6];

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 400.0, 0.0, 400.0, -1.0, 1.0);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Original Hexagon (Blue)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 6; i++)
    {
        glVertex2f(x[i], y[i]);
    }
    glEnd();

    // Scaled Hexagon (Red)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 6; i++)
    {
        glVertex2f(sx_h[i], sy_h[i]);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    printf("Enter scaling factor along X-axis (sx): ");
    scanf("%f", &sx);
    printf("Enter scaling factor along Y-axis (sy): ");
    scanf("%f", &sy);

    // Apply Scaling
    for(int i = 0; i < 6; i++)
    {
        sx_h[i] = sx * x[i];
        sy_h[i] = sy * y[i];
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Hexagon Scaling");

    init();
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}