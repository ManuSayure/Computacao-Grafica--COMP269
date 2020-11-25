#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>

static int year =0, day =0;
int yearL=0;

void init(void){
glClearColor(0.0,0.0,0.0,0.0);
}
void drawSolarSystem()
{
  /// Sun
  glPushMatrix();
    glColor3ub(255, 127, 80);
    glRotatef(year, 1, 0, 0);
    glRotatef(day, 0, 0, 1);
    glutSolidSphere(0.5, 100, 100);
  glPopMatrix();

  /// Planet 1
  glPushMatrix();
    glColor3ub(255, 255, 0);
    glRotatef(year, 0, 1, 0);
    glTranslatef(2, 0, 0);
    glPushMatrix();
      glRotatef(day, 0, 1, 0);
      glutSolidSphere(0.1, 100, 100); /// Planet 1
    glPopMatrix();

    glPushMatrix();
      glColor3ub(255, 0, 0);
      glRotatef(1.25*day, 0, 0, 1);
      glTranslatef(0.2, 0, 0);
      glutSolidSphere(0.05, 100, 100); /// Moon 1
    glPopMatrix();

    glPushMatrix();
      glColor3ub(0, 255, 0);
      glRotatef(1.5*day, 0, 1, 0);
      glTranslatef(0.4, 0, 0);
      glutSolidSphere(0.025, 100, 100); /// Moon 2
    glPopMatrix();

   /* glPushMatrix();
      glColor3ub(0, 0, 255);
      glRotatef(1.75*day, 0, 1, 1);
      glTranslatef(0.3, 0, 0);
      glutSolidSphere(0.025, 100, 100); /// Moon 3
    glPopMatrix();*/
  glPopMatrix();

  /// Planet 2
  glPushMatrix();
    glColor3ub(0, 255, 255);
    glRotatef(2*yearL, 0, 1, 0);
    glTranslatef(1, 0, 0);
    glRotatef(2*day, 0, 1, 0);
    glutSolidSphere(0.1, 10, 8); /// Planet 2
  glPopMatrix();
}
void display(void){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawSolarSystem();
    glPopMatrix();
    glutSwapBuffers();

}
void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	 glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
//	gluPerspective(25,(GLfloat)w/(GLfloat)h,0.4,500);
	gluPerspective(60.0, ((GLfloat)w / (GLfloat)h), 1.0, 20.0);
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0); //posicao da camera
}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'd':
			day = (day + 10)%360;
			glutPostRedisplay();
			break;
		case 'D':
			day = (day-10) % 360;
			glutPostRedisplay();
			break;
		case 'y':
            year = (year + 5) % 360;
            yearL = (yearL - 5) % 360;
			glutPostRedisplay();
			break;
		case 'Y':
            year = (year + 5) % 360;
            yearL = (yearL - 5) % 360;
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}




int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Rotação de Planetas");
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
 //  glutMouseFunc(MouseClick);
  glutMainLoop();
  return 0;
}
