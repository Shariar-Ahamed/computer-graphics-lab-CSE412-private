#include <GL/glut.h>
#include <cmath>

// Animation state variables
float robotX = -1.2f;
float gearAngle = 0.0f;

// Scaling parameters
float robotScale = 1.0f;
float scaleStep = 0.005f;

// Utility function to draw a solid circle using trigonometry
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

// Main display callback for rendering the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // Apply global animations (Translation and Scaling)
    glTranslatef(robotX, 0.0f, 0.0f);
    glScalef(robotScale, robotScale, 1.0f);

    // Render Main Body (Color: #FF4400)
    glColor3f(1.0f, 0.27f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.3f); glVertex2f( 0.2f, -0.3f);
        glVertex2f( 0.2f,  0.3f); glVertex2f(-0.2f,  0.3f);
    glEnd();

    // Render Rotating Gear (Chest)
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(gearAngle, 0.0f, 0.0f, 1.0f);

    // Gear background
    glColor3f(1.0f, 0.8f, 0.1f);
    drawCircle(0.0f, 0.0f, 0.12f);

    // Gear crosslines
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.12f, 0.0f); glVertex2f(0.12f, 0.0f);
        glVertex2f(0.0f, -0.12f); glVertex2f(0.0f, 0.12f);
    glEnd();
    glPopMatrix();

    // Render Arms (Vibrant Purple)
    glColor3f(0.6f, 0.2f, 0.8f);
    glBegin(GL_QUADS);
        // Left Arm
        glVertex2f(-0.35f, 0.1f); glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.2f, 0.2f);  glVertex2f(-0.35f, 0.2f);

        // Right Arm
        glVertex2f( 0.2f,  0.1f); glVertex2f( 0.35f, 0.1f);
        glVertex2f( 0.35f, 0.2f); glVertex2f( 0.2f,  0.2f);
    glEnd();

    // Render Legs (Color: #2F2FE4)
    glColor3f(0.18f, 0.18f, 0.89f);
    glBegin(GL_QUADS);
        // Left Leg
        glVertex2f(-0.15f, -0.5f); glVertex2f(-0.05f, -0.5f);
        glVertex2f(-0.05f, -0.3f); glVertex2f(-0.15f, -0.3f);

        // Right Leg
        glVertex2f( 0.05f, -0.5f); glVertex2f( 0.15f, -0.5f);
        glVertex2f( 0.15f, -0.3f); glVertex2f( 0.05f, -0.3f);
    glEnd();

    // Render Head (Color: White)
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.0f, 0.4f, 0.15f);

    // Render Eyes (Color: #38E54D)
    glColor3f(0.22f, 0.90f, 0.30f);
    glBegin(GL_TRIANGLES);
        // Left Eye
        glVertex2f(-0.08f, 0.4f); glVertex2f(-0.02f, 0.4f); glVertex2f(-0.05f, 0.45f);
        // Right Eye
        glVertex2f( 0.02f, 0.4f); glVertex2f( 0.08f, 0.4f); glVertex2f( 0.05f, 0.45f);
    glEnd();

    glPopMatrix();
    glFlush();
}

// Timer function to handle animations continuously
void timer(int) {
    // Update movement and rotation
    robotX += 0.01f;
    gearAngle -= 2.0f;

    // Handle scaling bounce effect
    robotScale += scaleStep;
    if (robotScale >= 1.5f || robotScale <= 0.5f) {
        scaleStep = -scaleStep;
    }

    // Reset position when off-screen
    if (robotX > 1.2f) {
        robotX = -1.2f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Approx 60 FPS
}

// Application entry point
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Robot Automatic Scaling - Custom Colors");

    // Dark background to make the new colors pop
    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}