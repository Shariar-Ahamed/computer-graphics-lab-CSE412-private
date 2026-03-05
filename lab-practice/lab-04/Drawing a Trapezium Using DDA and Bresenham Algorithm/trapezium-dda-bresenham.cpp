#include <GL/glut.h>
#include <math.h>

// ----------- DDA LINE ALGORITHM -----------

void drawLineDDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x = x + Xinc;
        y = y + Yinc;
    }

    glEnd();
}


// ----------- BRESENHAM LINE ALGORITHM -----------

void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    glBegin(GL_POINTS);

    while (true)
    {
        glVertex2i(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err = err - dy;
            x1 = x1 + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y1 = y1 + sy;
        }
    }

    glEnd();
}


// ----------- DISPLAY FUNCTION -----------

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);   // Red color
    glPointSize(5.0);

    // New Trapezium Points
    int x1 = 3,  y1 = 4;   // A
    int x2 = 17, y2 = 4;   // B
    int x3 = 14, y3 = 13;  // C
    int x4 = 6,  y4 = 13;  // D

    // Bottom (Bresenham)
    drawLineBresenham(x1, y1, x2, y2);

    // Right (Bresenham)
    drawLineBresenham(x2, y2, x3, y3);

    // Top (Bresenham)
    drawLineBresenham(x3, y3, x4, y4);

    // Left (DDA)
    drawLineDDA(x4, y4, x1, y1);

    glFlush();
}


// ----------- INIT -----------

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 20, 0, 20);
}


// ----------- MAIN -----------

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(200, 200);

    glutCreateWindow("Trapezium using DDA and Bresenham");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
