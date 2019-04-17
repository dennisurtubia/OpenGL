#include <GL/glut.h>
#include <stdio.h>

int point1[] = {0, 0};
int point2[] = {10, 0};
int point3[] = {10, 10};
int point4[] = {0, 10};

int x = 0;
int y = 0;
int angle = 0;
int stepSize = 2;
int mode = 0; //0 translation, 1 rotation

int init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 100., 0.0, 100.0);
}

void displayMe(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(x, y, 0);

	glTranslatef(5, 5, 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-5, -5, 0);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);

	glVertex2i(point1[0], point1[1]);
	glVertex2i(point2[0], point2[1]);
	glVertex2i(point3[0], point3[1]);
	glVertex2i(point4[0], point4[1]);

	glEnd();
	glFlush();
}

void specialKeys(int key, int mx, int my) {
	if (key == GLUT_KEY_LEFT) {
		if (mode == 0) x -= stepSize;
		if (mode == 1) angle += 5;
	}
	else if (key == GLUT_KEY_RIGHT) {
		if (mode == 0) x += stepSize;
		if (mode == 1) angle -= 5;
	}
	else if (key == GLUT_KEY_UP) {
		if (mode == 0) y += stepSize;
	} 
	else if (key == GLUT_KEY_DOWN) {
		if (mode == 0) y -= stepSize;
	}
	glutPostRedisplay();
}

void normalKeys(unsigned char key, int x, int y) {
	if (key == 'T' || key == 't')	mode = 0;
	else if (key == 'R' || key == 'r') 	mode = 1;
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("First Bonus");
	init();
	glutDisplayFunc(displayMe);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(normalKeys);
	glutMainLoop();

	return 0;
}