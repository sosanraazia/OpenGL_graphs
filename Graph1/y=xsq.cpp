#include <GL/freeglut.h>
#include <iostream>

using namespace std;

const int WIDTH = 512;
const int HEIGHT = 512;

void OnRender(void) {


	glClear(GL_COLOR_BUFFER_BIT);

	//for minor axis
	glColor3f(0.5, 0.5, 0.5);//gray color 
	glBegin(GL_LINES);
	for (int i = -50; i <= 50; ++i) //loop over 100 values
	{
		float x = float(i) / 50; //set the values between -1 to 1
		glVertex2f(x, -1);			glVertex2f(x, 1); //for x axis
		glVertex2f(-1, x);			glVertex2f(1, x); // for y axis
	}
	glEnd();

	//for major axis
	glColor3f(0.0, 0.0, 0.0);//black color 
	glBegin(GL_LINES);
	for (int i = -5; i <= 5; ++i) //loop over 10 values
	{
		float x = float(i) / 5; // set values between -1 to 1 
		glVertex2f(x, -1);			glVertex2f(x, 1); //for x axis
		glVertex2f(-1, x);			glVertex2f(1, x); //for y axis
	}
	glEnd();

	//y=x^2
	glColor3f(1.0, 0.0, 0.0);//red color 
	glPointSize(3); //increase size of points
	glBegin(GL_POINTS); //plot points
	for (int i = -50; i <= 50; ++i) //loop over 100 values
	{

		float x = float(i) / 50; // set values between -1 to 1 
		glVertex2f(x, x*x);		//Plot points x value ranges from -1 to 1 and y will be calculated for each value of x as x^2

	}
	glEnd();

	glColor3f(0.0, 0.5, 1.0);//change color  
	glBegin(GL_LINES); // draw lines passing through all the points plotted in the previous loop
	for (int i = -50; i <= 50; ++i) //loop over 100 values
	{
		float x = float(i) / 50; // set values between -1 to 1 
		glVertex2f(x, x*x);

		++i; //inc i to calculate the next vertex of the line
		x = float(i) / 50; //calc x for the next vertex of the line
		glVertex2f(x, x*x);

		--i;//restore i to prev value.
	}
	glEnd();

	glutSwapBuffers();
}
void OnInit() {
	glClearColor(1, 1, 1, 1);// set background color to white
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Graph y=x^2");
	glutDisplayFunc(OnRender);

	OnInit();
	glutMainLoop();
	return 0;
}