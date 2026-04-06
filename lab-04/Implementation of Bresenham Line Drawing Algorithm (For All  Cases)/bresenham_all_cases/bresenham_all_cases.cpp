#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int x1_input, y1_input, x2_input, y2_input;

void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);

    while (x <= x2)
    {
        glVertex2i(x, y);

        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        x = x + 1;
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(6.0);

    drawLineBresenham(x1_input, y1_input, x2_input, y2_input);

    glFlush();
}

void init()
{
    glClearColor(0.9, 0.9, 0.9, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 100, 0, 100);
}

int main(int argc, char** argv)
{
    printf("Enter x1 y1: ");
    scanf("%d %d", &x1_input, &y1_input);

    printf("Enter x2 y2: ");
    scanf("%d %d", &x2_input, &y2_input);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Bresenham Line Drawing Algorithm (User Input)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}