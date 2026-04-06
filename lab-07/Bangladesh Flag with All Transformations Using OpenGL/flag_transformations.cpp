#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int option;
float wave = 0;

// Translation
float tx = 0, ty = 0;

// Scaling
float sx = 1, sy = 1;

// Shearing
float shx = 0, shy = 0;

// Reflection
int refChoice;

// ================= FLAG =================
void drawPole()
{
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(-150, -150);
    glVertex2f(-140, -150);
    glVertex2f(-140, 150);
    glVertex2f(-150, 150);
    glEnd();
}

void drawFlag()
{
    float startX = -140;
    float width = 220;
    float topY = 150;
    float bottomY = 50;

    glColor3f(0, 0.6, 0);

    glBegin(GL_QUADS);
    for (int i = 0; i <= 40; i++)
    {
        float t = i / 40.0;
        float x = startX + t * width;
        float offset = sin(wave - t * 3) * (5 + t * 10);

        float yTop = topY + offset;
        float yBottom = bottomY + offset;

        float nextT = (i + 1) / 40.0;
        float nextX = startX + nextT * width;
        float nextOffset = sin(wave - nextT * 3) * (5 + nextT * 10);

        glVertex2f(x, yTop);
        glVertex2f(nextX, topY + nextOffset);
        glVertex2f(nextX, bottomY + nextOffset);
        glVertex2f(x, yBottom);
    }
    glEnd();

    // Red Circle
    glColor3f(1, 0, 0);
    float cx = startX + 90;
    float cy = 100;

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float ang = 2 * 3.1416 * i / 100;
        float offset = sin(wave - 1.5) * 10;
        glVertex2f(cx + 25 * cos(ang), cy + 25 * sin(ang) + offset);
    }
    glEnd();
}

// ================= DISPLAY =================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // OPTION 1 → 4 flags
    if(option == 1)
    {
        glPushMatrix(); glTranslatef(-150, 100, 0); drawPole(); drawFlag(); glPopMatrix();
        glPushMatrix(); glTranslatef(150, 100, 0); drawPole(); drawFlag(); glPopMatrix();
        glPushMatrix(); glTranslatef(-150, -100, 0); drawPole(); drawFlag(); glPopMatrix();
        glPushMatrix(); glTranslatef(150, -100, 0); drawPole(); drawFlag(); glPopMatrix();
    }

    // OPTION 2 → Scaling
    else if(option == 2)
    {
        drawPole();
        glScalef(sx, sy, 1);
        drawFlag();
    }

    // OPTION 3 → Translation (Move with keys)
    else if(option == 3)
    {
        glTranslatef(tx, ty, 0);
        drawPole();
        drawFlag();
    }

    // OPTION 4 → Reflection
    else if(option == 4)
    {
        drawPole();
        drawFlag();

        glPushMatrix();
        if(refChoice == 1) glScalef(1, -1, 1);
        else if(refChoice == 2) glScalef(-1, 1, 1);
        else glScalef(-1, -1, 1);

        drawFlag();
        glPopMatrix();
    }

    // OPTION 5 → Shearing
    else if(option == 5)
    {
        drawPole();

        GLfloat shear[16] = {
            1, shy, 0, 0,
            shx, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        glMultMatrixf(shear);
        drawFlag();
    }

    glPopMatrix();

    glutSwapBuffers();
}

// ================= KEYBOARD =================
void specialKeys(int key, int x, int y)
{
    if(option == 3)
    {
        if(key == GLUT_KEY_UP) ty += 10;
        if(key == GLUT_KEY_DOWN) ty -= 10;
        if(key == GLUT_KEY_LEFT) tx -= 10;
        if(key == GLUT_KEY_RIGHT) tx += 10;
        glutPostRedisplay();
    }
}

// ================= ANIMATION =================
void update(int v)
{
    wave += 0.08;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// ================= INIT =================
void init()
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-400, 400, -300, 300, -1, 1);
}

// ================= MAIN =================
int main(int argc, char** argv)
{
    printf("Select Option:\n");
    printf("1. 4 Flags (Translation)\n");
    printf("2. Scaling Flag\n");
    printf("3. Translation (Move Flag)\n");
    printf("4. Reflection\n");
    printf("5. Shearing\n");
    printf("Enter choice: ");
    scanf("%d", &option);

    if(option == 2)
    {
        printf("Enter sx, sy: ");
        scanf("%f %f", &sx, &sy);
    }
    else if(option == 4)
    {
        printf("1.X-axis  2.Y-axis  3.Origin\n");
        scanf("%d", &refChoice);
    }
    else if(option == 5)
    {
        printf("Enter shx, shy: ");
        scanf("%f %f", &shx, &shy);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Flag Project (All Transformations)");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
}