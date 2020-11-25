#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
//#include "flor.h"

const double PI = 3.141592654;
int direcao = 1;
int grau = 0;
const float cores[4][3] =
    {
        {0.0f,1.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {0.0f,0.0f,1.0f},
        {1.0f,1.0f,0.0f}
    };

void MouseRotate(int button, int x, int y, int state)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            ++direcao;
        break;
        case GLUT_RIGHT_BUTTON:
            --direcao;
        break;
    }
}

void desenha() {
    float x = 0.0f;
    int i;
    float centroX = 0.0f;
    float centroY = 0.2f;

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(x, -0.8f);
    glVertex2f(x+0.005f, 0.2f);
    glVertex2f(x-0.005f, 0.2f);

    glEnd();

    for (i = 0; i < 4; i++) {
        glColor3f(cores[i][0],cores[i][1],cores[i][2]);

        glBegin(GL_TRIANGLES);

        glVertex2f(x+centroX, centroY);
        glVertex2f();
        glVertex2f();

        glEnd();
    }
}

void displayFnc() {

    glClear(GL_COLOR_BUFFER_BIT);

    glutMouseFunc(MouseRotate);

    desenha();

    glutSwapBuffers();

}

void desenha_Frame(int v) {
    grau += direcao; ///se o botão esquerdo do mouse for acionado os graus ficam negativos
    glutPostRedisplay();
    glutTimerFunc(20,desenha_Frame,0);
}

void init() {
    glClearColor(1.0f, 0.5f, 0, 1);
}

