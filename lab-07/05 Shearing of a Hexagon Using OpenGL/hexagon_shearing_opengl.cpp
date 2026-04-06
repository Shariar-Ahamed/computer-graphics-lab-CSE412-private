#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

// Original Hexagon points
float x[6] = {100, 130, 130, 100, 70, 70};
float y[6] = {150, 130, 100, 70, 100, 130};

// Shear factors
float shx = 0, shy = 0;
int choice;

// Sheared coordinates
float nx[6], ny[6];

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

    // Original Hexagon
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<6;i++)
        glVertex2f(x[i], y[i]);
    glEnd();

    // Sheared Hexagon
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<6;i++)
        glVertex2f(nx[i], ny[i]);
    glEnd();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    printf("Choose Shearing Type:\n");
    printf("1. Shearing along X-axis (Horizontal Shear)\n");
    printf("2. Shearing along Y-axis (Vertical Shear)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter shear factor along X-axis (shx): ");
        scanf("%f", &shx);

        // Horizontal Shear
        for(int i=0;i<6;i++)
        {
            nx[i] = x[i] + shx * y[i];
            ny[i] = y[i];
        }
    }
    else if(choice == 2)
    {
        printf("Enter shear factor along Y-axis (shy): ");
        scanf("%f", &shy);

        // Vertical Shear
        for(int i=0;i<6;i++)
        {
            nx[i] = x[i];
            ny[i] = y[i] + shy * x[i];
        }
    }
    else
    {
        printf("Invalid choice! Program will exit.");
        return 0;
    }

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Shearing Hexagon");

    init();
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}