#include <GL/glut.h>
#include <math.h>

float wave = 0.0;

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -1, 1);
}

// 🪵 Pole (static)
void drawPole()
{
    glColor3f(0.55, 0.27, 0.07); // wood color
    glBegin(GL_QUADS);
        glVertex2f(-150, -150);
        glVertex2f(-140, -150);
        glVertex2f(-140, 150);
        glVertex2f(-150, 150);
    glEnd();
}

// Flag (wind: Left → Right)
void drawFlag()
{
    float startX = -140;
    float width = 220;

    float topY = 150;
    float bottomY = 50;

    // Green flag
    glColor3f(0, 0.6, 0);

    glBegin(GL_QUADS);
    for (int i = 0; i <= 50; i++)
    {
        float t = i / 50.0;
        float x = startX + t * width;

        // LEFT → RIGHT wind
        float offset = sin(wave - t * 3) * (5 + t * 10);

        float yTop = topY + offset;
        float yBottom = bottomY + offset;

        float nextT = (i + 1) / 50.0;
        float nextX = startX + nextT * width;
        float nextOffset = sin(wave - nextT * 3) * (5 + nextT * 10);

        float nextYTop = topY + nextOffset;
        float nextYBottom = bottomY + nextOffset;

        glVertex2f(x, yTop);
        glVertex2f(nextX, nextYTop);
        glVertex2f(nextX, nextYBottom);
        glVertex2f(x, yBottom);
    }
    glEnd();

    // Red circle (same motion)
    glColor3f(1, 0, 0);

    float cx = startX + 90;
    float cy = (topY + bottomY) / 2;

    float baseOffset = sin(wave - 0.4 * 3) * (5 + 0.4 * 10);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        float x = cx + 25 * cos(angle);
        float y = cy + 25 * sin(angle) + baseOffset;

        glVertex2f(x, y);
    }
    glEnd();
}

// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawPole();
    drawFlag();

    glutSwapBuffers();
}

// Animation
void update(int value)
{
    wave += 0.08; // smooth speed
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutCreateWindow("Bangladesh Flag (Wind Left -> Right)");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}