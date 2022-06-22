//改进的Bresenham算法生成直线段
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<stdio.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void ProBresenham(int x0, int y0, int xEnd, int yEnd){    //改进的Bresenham算法画线
	int x, y, dx, dy, e;
	dx = xEnd - x0;
	dy = yEnd - y0;
	e = -dx;
	x = x0;
	y = y0;
	while (x <= xEnd) {
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		x++;
		e = e + 2 * dy;
		if (e > 0) {
			y++;
			e = e - 2 * dx;
		}
	}
 }

void lineSegment(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	int x0, y0, xEnd, yEnd;
	printf("请输入第一个点的坐标:\n");
	scanf("%d%d", &x0, &xEnd);
	printf("请输入第二个点的坐标:\n");
	scanf("%d%d", &y0, &yEnd);
	ProBresenham(x0, y0, xEnd, yEnd);
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("改进的Bresenham算法生成直线段：");
	glutDisplayFunc(&lineSegment);
	init();
	glutMainLoop();
}