//BresenBam 算法生成直线段
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<stdio.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void setPixel(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void lineBres(int x0, int y0, int xEnd, int yEnd) {
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;

	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0;
		y = y0;
	}
	setPixel(x, y);

	while (x < xEnd) {
		x++;
		if (p < 0) {
			p += twoDy;
		}
		else {
			y++;
			p += twoDyMinusDx;
		}
		setPixel(x, y);
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
	lineBres(x0, y0, xEnd, yEnd);
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bresenham算法生成直线段");
	glutDisplayFunc(&lineSegment);
	init();
	glutMainLoop();
}