#include <windows.h>     
#include "glut.h"

/* To-dos:

- Fix grid size, right now it's 8x8
- Fix mouse control
- Change grids to appropiate colors/images
- Add collision detection on vertices
- Get rid of console window popping up

*/

/* Known bugs:

- Mouse control fucks up when clicking the board, instead
of moving the peice, it'll rotate the whole window, not sure why

- Compiler warning C4113 (can be fixed with a typecast as void on line 52),
program will still compile and run

*/

// Need to fix this so it's not global
int color = 0;
GLint width = 800;
GLint hight = 600;

// Can probably do it in a struct, but too lazy
/*
typedef struct Settings {
	int color;
	GLint width;
	GLint height;
}
*/

void init();
void drawBoard();
void drawSquare();

int main(int agrc, char** argv) {
	// Use this if we want main() to invoke 0 arguments
	/*
	char *myargv [1];
	int myargc=1;
	myargv [0]=strdup ("CIS 27 - Klotski Final Project");
	glutInit(&myargc, myargv);
	*/
	glutInit(&agrc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("CIS 27 - Klotski Final Project");
	init();
	glutDisplayFunc(drawBoard);
	glutMainLoop();
}

void init() {
	glClearColor(0, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, 0, hight);
}

// Draws the square
void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4) {
	if (color == 0) {
		glColor3f(1, 1, 1);
		color = 1;
	} else {
		glColor3f(0, 0, 0);
		color = 0;
	}

	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
}

// Draws an 8x8 board
void drawBoard() {
	glClear(GL_COLOR_BUFFER_BIT);
	GLint x, y;
	GLint squareWidthInPixel = 100;
	GLint squareHightInPixel = 75;

	for (x = 0; x <= width; x += squareWidthInPixel) {
		for (y = 0; y <= hight; y += squareHightInPixel) {
			drawSquare(x, y + squareHightInPixel, x + squareWidthInPixel, y + squareHightInPixel, x + squareWidthInPixel, y, x, y);
		}
	}

	glFlush();
}