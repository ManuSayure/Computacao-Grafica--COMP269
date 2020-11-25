#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "blocos.h"
#define n_elem 6

int direcao = 1;
int active_blocks[n_elem];

// delay for movement
int flag = 0;
int max_flag = 15;

// all blocks going baixo?
int baixo = 0;

// blocks stats
float altura = 0.3f;
float largura = 0.3f;
float x[n_elem];
float y[n_elem];
float velocidade = 0.01f;

void direcaoFnc(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            ++direcao;
            if(direcao > 1)
                direcao = 1;
        break;
        case GLUT_KEY_RIGHT:
            --direcao;
            if(direcao < -1)
                direcao = -1;
        break;
    }
}
void desenhaBlocos() {
    int i = 0;
    for(i=0;i<n_elem;++i){
        glColor3f(0.05f*i, 0.1f*i, 0.2f);

        glBegin(GL_POLYGON);

        glVertex2f(x[i], y[i]+altura);
        glVertex2f(x[i]+largura, y[i]+altura);
        glVertex2f(x[i]+largura, y[i]);
        glVertex2f(x[i], y[i]);

        glEnd();
    }
}
void displayFnc() {

    glClear(GL_COLOR_BUFFER_BIT);

    glutSpecialFunc(direcaoFnc);
    desenhaBlocos();

    glutSwapBuffers();

}
int switch_block(int posicao) {
	if(active_blocks[posicao] == 0){
        if(flag==max_flag){
            active_blocks[posicao] = 1;
            flag=0;
        }
        else
            ++flag;
        return 1;
    }

    return 0;
}
void blocks_doFrame(int v) {
    int i;
    int num_finished = 0;

    // direcaos

    if(direcao == 0)
        blocks_init();
    else if(direcao == 1){
        for(i=0;i<n_elem;++i){
            if (switch_block(i)) break;
        }
    }
    else {
        for(i=n_elem-1;i>=0;--i){
            if (switch_block(i)) break;
        }
    }

    // up!
    if (baixo == 0) {
        for(i=0;i<n_elem;++i){
            if(active_blocks[i] == 1 && y[i] <altura){
                y[i] += velocidade;
            } else if (active_blocks[i] == 1 && y[i] >=altura) {
                ++num_finished;
            }
        }
    // baixo!
    } else {
        for(i=0;i<n_elem;++i){
            if(y[i] > 0) {
                y[i] -= velocidade;
            } else {
                active_blocks[i] = 0;
                baixo = 0;
            }
        }
    }

    // change to up?
    if (baixo == 0)
        baixo = (num_finished == n_elem);

    glutPostRedisplay();
    glutTimerFunc(20,blocks_doFrame,0);
}
void init() {
    glClearColor(1.0f, 0.6f, 0, 1);
    int i = 0;
    for(i = 0; i < n_elem; ++i) {
        active_blocks[i] = 0;
        x[i] = (i-3)*width;
        y[i] = 0;
    }
}

