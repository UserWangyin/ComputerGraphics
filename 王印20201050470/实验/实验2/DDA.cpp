//DDA直线生成算法
#include <stdlib.h>
#include <math.h>
#include<GL/glut.h>
#include <stdio.h>

inline int round(const float a) { 
	return int(a + 0.5); 
}
void setPixel(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void lineDDA(int x0, int y0, int xEnd, int yEnd) {
	int dx = xEnd - x0;
	int dy = yEnd - y0;
	int steps, k;
	float xIncrement, yIncrement, x = x0, y = y0;
	if (fabs(dx) > fabs(dy)) {
		steps = fabs(dy);
	}
	else
		steps = fabs(dx);
	xIncrement = float(dx) / float(steps);
	yIncrement = float(dy) / float(steps);
	setPixel(round(x), round(y));
	for (k = 0; k < steps; k++) {
		x += xIncrement;
		y += yIncrement;
		setPixel(round(x), round(y));
	}
}
//初始化方法
void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void lineSegment(void) {

	int x1, y1, x2, y2;
	//glViewport(0, 0, 500, 500);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	glBegin(GL_LINES);
	printf("第一个坐标：");
	scanf("%d %d", &x1, &y1);
	printf("第二个坐标:");
	scanf("%d%d", &x2, &y2);
	lineDDA(x1, y1, x2, y2);
	glEnd();
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DDA生成直线段");
	glutDisplayFunc(lineSegment);
	Init();
	glutMainLoop();
}