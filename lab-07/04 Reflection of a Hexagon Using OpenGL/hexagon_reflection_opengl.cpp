#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

// Original Hexagon center
float x = 100, y = 100;

// Reflected center
float rx, ry;

int choice;

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-400.0, 400.0, -400.0, 400.0, -1.0, 1.0);
}

// ⬡ Draw Hexagon
void drawHexagon(float cx, float cy)
{
    glBegin(GL_POLYGON);

    glVertex2f(cx + 0,   cy + 40);
    glVertex2f(cx + 30,  cy + 20);
    glVertex2f(cx + 30,  cy - 20);
    glVertex2f(cx + 0,   cy - 40);
    glVertex2f(cx - 30,  cy - 20);
    glVertex2f(cx - 30,  cy + 20);

    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Original Hexagon (Top)
    glColor3f(1.0, 0.0, 0.0);
    drawHexagon(x, y);

    // Reflected Hexagon (Bottom)
    glColor3f(1.0, 1.0, 0.0);
    drawHexagon(rx, ry);

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    printf("Choose Reflection Type:\n");
    printf("1. Reflection about X-axis\n");
    printf("2. Reflection about Y-axis\n");
    printf("3. Reflection about Diagonal (Origin)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        // X-axis
        rx = x;
        ry = -y;
    }
    else if(choice == 2)
    {
        // Y-axis
        rx = -x;
        ry = y;
    }
    else if(choice == 3)
    {
        // Origin
        rx = -x;
        ry = -y;
    }
    else
    {
        printf("Invalid choice!");
        return 0;
    }

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("2D Reflection (Hexagon)");

    init();
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}