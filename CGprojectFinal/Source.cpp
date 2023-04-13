//iostream libary for input and output 
#include <iostream>
//this line helps prevent writing  "std" each time i want to print 
using namespace std;
//pencil 
#include <GL\glew.h>
//glut (paper)
#include <GL\freeglut.h>

double PI = 3.14159265358979323846;
float gray[] = { 0.86275, 0.87059, 0.86667, 1 };
float blue[] = { 0.18824, 0.35686, 0.47843 ,0 };
float bluue[] = { 0.16471, 0.27451, 0.36863 ,0 };
float ge[] = { 0.80000, 0.80000, 0.80000 ,0 };

void createCircle(float xi, float yi, float r, float color[4]) {
	float x, y;
	float angel = (2.0f * PI) / 180;
	glColor4fv(color);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(xi, yi);
	for (int i = 0; i <= 180; i++) {
		glVertex2f(
			xi + (r * cos(i * angel)),
			yi + (r * sin(i * angel))
		);

	}
	glEnd();
	glFlush();
}


//  Functions 
static void head() {
	
	createCircle(0.359, -0.05, 0.15, gray);
	createCircle(0.359, -0.05, 0.11, bluue);
	createCircle(0.376, -0.038, 0.09, blue);
	
}

static void b() {
	glBegin(GL_QUADS); // the cup of the cake
	glColor3f(0.86275, 0.87059, 0.86667);

	//sqare body//
	glVertex2f(0.24, -0.2);
	glVertex2f(0.488, -0.2);
	glVertex2f(0.488, -0.5);
	glVertex2f(0.24, -0.5);


	//right arm//
	glVertex2f(0.48, -0.2);
	glVertex2f(0.61, -0.34);
	glVertex2f(0.56, -0.38);
	glVertex2f(0.48, -0.3);

	//left arm //
	glVertex2f(0.24, -0.2);
	glVertex2f(0.1, -0.34);
	glVertex2f(0.15, -0.38);
	glVertex2f(0.24, -0.3);


	//right leg  //
	glVertex2f(0.46, -0.5);
	glVertex2f(0.46, -0.65);
	glVertex2f(0.375, -0.65);
	glVertex2f(0.375, -0.5);

	//left leg //
	glVertex2f(0.27, -0.65);
	glVertex2f(0.35, -0.65);
	glVertex2f(0.35, -0.5);
	glVertex2f(0.27, -0.5);

	
	
	

	glEnd();
	glFlush();
}

static void roundsq() {
	glBegin(GL_QUADS);
	glColor3f(0.80000, 0.80000, 0.80000);
	glVertex2f(0.466, -0.21);
	glVertex2f(0.506, -0.21);
	glVertex2f(0.506, -0.299);
	glVertex2f(0.466, -0.299);
	createCircle(0.485, -0.21, 0.0156, ge);
	createCircle(0.485, -0.299, 0.0156, ge);
	//---------------------
	
	glEnd();
	glFlush();
}
static void details() {
	//left square+Circle detail
	roundsq();
	glPushMatrix();
	glTranslatef(-0.24,0,0);
	roundsq();
	glPopMatrix();
	//---------------------
	//glPushMatrix();
	////glRotatef(-1.4, 0, 0,1);
	//glTranslatef(0.07, -0.08, 0);
	//
	//roundsq();
	//glPopMatrix();
	glPushMatrix();
	createCircle(0.418, -0.645, 0.045, ge);
	createCircle(0.309, -0.645, 0.045, ge);
	glPopMatrix();

	glPushMatrix();
	glLineWidth(20.0f);
    glClearColor(1.0, 1.0, 0.9, 0.0);
	glBegin(GL_LINES);
	
	glVertex2f(0.2, -0.68);
    glVertex2f(0.5, -0.68);
	glEnd();
	glFlush();
	glPopMatrix();

}


//FUNCTION point  
void Display() {
	//before drawing clear buffer
	glClear(GL_CLEAR_BUFFER);
	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	b();
	head();
	details();
	//glPointSize(20.00f);
	//the type of drawing i want to draw 
	//glBegin(GL_POINTS);
	//the color of the pencil
	//glColor3f(1.0, 0.4, 0.4);
	//POINTS 2D(2f) xy if 3D(3f) xyz 
	
	glEnd();
	//put it on the screen 
	glFlush();


}

// give the point of my click in mouse
void printCoords(int button, int state, int x, int y) {

	// window range
	double min = 0, max = 600;

	// normalized range
	int a = -10, b = 10;

	// calculte the normalized coordinates
	double xNormalized = a + ((x - min) * (b - a)) / (max - min);
	double yNormalizedY = b + ((y - min) * (a - b)) / (max - min);

	// print the normalized coordinates when left click
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		printf("(%0.2f, %0.2f)\n", xNormalized, yNormalizedY);
}
void mouse(int button, int state, int x, int y) {
	printCoords(button, state, x, y);
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	//number of buffers nedded for the drawing 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//paper size 
	glutInitWindowSize(500, 500);
	//where i want the drawing to be displayed 
	glutInitWindowPosition(100, 100);
	//label of drawing
	glutCreateWindow("pro");


	glMatrixMode(GL_PROJECTION);
	//clear the page (easer color)
	glClearColor(1.0, 1.0, 0.9, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutMouseFunc(mouse);
	//glutMouseFunc(printCoords);
	//goes to func and prints it on the screen
	glutDisplayFunc(Display);

	glutMainLoop();



	return 0;
}