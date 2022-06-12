//实现任一反走样技术

#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
#define x_Screen 800
#define y_Screen    600
#define little 50
#define middle 20
#define large   8
void myBackground()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
}

void myDisplay()
{
	glEnable(GL_DEPTH_TEST);
	//如果没有抗锯齿，则点为方形的。如果我们启动抗锯齿设置，则点是一个圆点。
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);  // Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int i;
	glBegin(GL_POINTS);
	for (i = 0; i < little; i++)
		glVertex2f(50.0 + rand() % x_Screen, 50.0 + rand() % y_Screen);
	glEnd();
	glPointSize(2);
	glBegin(GL_POINTS);
	for (i = 0; i < middle; i++)
		glVertex2f(50.0 + rand() % x_Screen, 50.0 + rand() % y_Screen);
	glEnd();
	glPointSize(8);
	glBegin(GL_POINTS);
	for (i = 0; i < large; i++)
		glVertex2f(50.0 + rand() % x_Screen, 50.0 + rand() % y_Screen);
	glEnd();

	glBegin(GL_POLYGON);
	for (i = 0; i < 64; i++)
		glVertex2f(600 + 50.0 * cos((float)i / 10), 500 + 50.0 * sin((float)i / 10));
	glEnd();
	glLineWidth(3);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 19; i++) {
		glVertex2f(rand() % 10 + i * 70, rand() % 50 + 50.0 + (i % 2) * 80);
	}
	glEnd();
	glutSwapBuffers();
}
void myChange(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, x_Screen, 0.0, y_Screen);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(x_Screen, y_Screen);
	glutCreateWindow("StarStar");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myChange);
	myBackground();
	glutMainLoop();
}
