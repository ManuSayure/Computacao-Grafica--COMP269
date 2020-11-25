#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
const double PI = 3.141592654;
static int shoulder = 0, sen = 0;
int controle = 0;
float cores[4][3] =
    {
        {0.0f,1.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {0.0f,0.0f,1.0f},
        {1.0f,1.0f,0.0f}
    };

void init(void){
  glClearColor (0.0,0,0,0);
}
void reshape (int w, int h){

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}
void direcao(int controle){
    int r,g,b;
    ///gira pra direita
    if(controle == 1){
        r = cores[0][0]; g = cores[0][1];  b = cores [0][2];
        for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cores[i][j]= cores[i+1][j];
                }
        }
        cores[3][0]= r; cores[3][1] = g; cores[3][2] = b;
    }
    /// gira pra esquerda
    else if(controle ==0){
         r = cores[3][0]; g = cores[3][1]; b = cores [3][2];
        for(int i=3; i>0; i--){
                for(int j=0; j<3; j++){
                    cores[i][j]= cores[i-1][j];
                }
        }
        cores[0][0]= r; cores[0][1] = g; cores[0][2] = b;
    }
}

void MouseClick (int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        controle = 0;
        direcao(controle);
        glutPostRedisplay();
  }
  if(button == GLUT_RIGHT_BUTTON&& state == GLUT_DOWN){
        controle = 1;
        direcao(controle);
        glutPostRedisplay();
   }
}
float get_rad(float mod, float mult) {
    return (mod + 90 * mult) * PI/180;
}
void drawPetals() {

        for (int i = 0; i < 4; i++) {
          glColor3f(cores[i][0],cores[i][1],cores[i][2]);
            glBegin(GL_TRIANGLES);
                glVertex2d(0, 0);
                glVertex2d(-2 / 2, -2);
                glVertex2d(2 / 2, -2);
            glEnd();
            glRotated(90, 0, 0, 1);
        }
    glPopMatrix();
}
void display(void){

  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /* origem posicionada */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  /* origem posicionada no centro*/
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  //haste do catavento
      glLineWidth(5.0f);
      glBegin(GL_LINES);
            glColor3f(139, 60, 19);
            glVertex2i(2, 0);
            glVertex2i(2, -5);
      glEnd();
  glPopMatrix();

  /* origem posicionada  */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) sen, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);

    glPushMatrix();
    drawPetals();

  /*volta para o sistema de coordenadas original */
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (700, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  //glutKeyboardFunc(keyboard);
   glutMouseFunc(MouseClick);
  glutMainLoop();
  return 0;
}
