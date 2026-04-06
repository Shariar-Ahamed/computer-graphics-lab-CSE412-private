#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0, -15.0, 15.0, -1.0, 1.0);

}


void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=6;i++)

    {
        float angle = 2.0f * 3.1416f * i/6;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);


    circle(3,3,0,0);
    glFlush();

glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}