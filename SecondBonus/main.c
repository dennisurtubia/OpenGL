#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int height;
int width;
GLfloat spin;

void createViewPort0() {
    glViewport(0, height / 2, width / 2, height / 2);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-3, 3, -3, 3, 1, 50);
    glLoadIdentity();
    glColor3f(1.0f, 0, 0);
    gluLookAt(0.0f, -0.5f, 0.0f, 
              0.0f, 0.0f, 0.0f,
              0.0f, 0.0f, 1.0f);
    glutWireTeapot(0.5f);
}

void createViewPort1() {
    glViewport(width / 2, height / 2, width / 2, height / 2);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-3, 3, -3, 3, 1, 50);
    glLoadIdentity();
    glColor3f(1.0f, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0f, 0.0f, 0.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    glutWireTeapot(0.5f);
}

void createViewPort2() {
    glViewport(0, 0, width / 2, height / 2);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-3, 3, -3, 3, 1, 50);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0f, 0, 0);
    glutWireTeapot(0.5f);
}

void createViewPort3() {
    glViewport(width / 2, 0, width / 2, height / 2);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(70, 1, 1, 50);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(spin, 0, 0, 1.0);
    glRotatef(45, 1.0, 0, 0);
    glColor3f(1.0f, 0, 0);
    glutWireTeapot(0.5f);
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glOrtho(-3, 3, -3, 3, 1, 50);
}

void displayMe() {
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    createViewPort0();
    createViewPort1();
    createViewPort2();
    createViewPort3();

    glEnd();
	glFlush();
}

void rotation(void) {
    spin += 1.5;
    displayMe();
}

void reshape(int w, int h) {
    width = w;
    height = h;
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    int screenWidth = (glutGet(GLUT_SCREEN_WIDTH) - 640) / 2;
    int screenHeight = (glutGet(GLUT_SCREEN_HEIGHT) - 480) / 2;

    glutInitWindowPosition(screenWidth, screenHeight);
    glutInitWindowSize(800, 800);
	
    glutCreateWindow("Second Bonus");

	init();
	glutDisplayFunc(displayMe);
    glutReshapeFunc(reshape);
    glutIdleFunc(rotation);
	glutMainLoop();

	return 0;
}
