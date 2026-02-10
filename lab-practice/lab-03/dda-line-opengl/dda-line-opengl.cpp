#include <GL/glut.h>
#include <math.h>

void drawLineDDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y)); // Rounded Pixel
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Red line
    glPointSize(6.0);

    // DDA Line from (5,4) to (12,7)
    drawLineDDA(5, 4, 12, 7);

    glFlush();
}

void init()
{
    glClearColor(0.9, 0.9, 0.9, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 20, 0, 20);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DDA Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}