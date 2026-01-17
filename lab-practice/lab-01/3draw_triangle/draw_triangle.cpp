#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);   // Red color

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);  // Vertex 1
        glVertex2f( 0.5, -0.5);  // Vertex 2
        glVertex2f( 0.0,  0.5);  // Vertex 3
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.6, 0.8, 1.0, 1.0); // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("OpenGL Triangle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}