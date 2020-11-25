#include "bresenham.h"
#include<windows.h>
#include <algorithm>
#include <GL/gl.h>
//#include <GL/glut.h>
#include <QtOpenGL>

using namespace std;

//Inspirado em https://marciobueno.com/arquivos/ensino/cg/CG_03_Primitivas_Graficas.pdf
// Option 1 = circulo completo
// Option 2 = semi circulo esquerdo
// Option 3 = semi circulo direito

void Bresenham::setpoint(int x,int y, float r, float g, float b, int line){
    glPointSize(line);

    glBegin(GL_POINTS);
        glColor3f(r, g, b);
        glVertex2i(x, y);
    glEnd();

    glFlush();
}

void Bresenham::ponto_circulo(int x, int y, int valor, int xc, int yc,int option, float r, float g, float b)
{
    //Circulo completo ou semi circulo direito
    if(option != 2){
        setpoint(x+xc, y+yc, r, g, b, valor);
        setpoint(y+xc, x+yc, r, g, b, valor);
        setpoint(y+xc, -x+yc, r, g, b, valor);
        setpoint(x+xc,-y +yc, r, g, b, valor);
    }
    //Circulo completo ou semi circulo esquerdo
    if(option != 3){
        setpoint(-x+xc, -y+yc, r, g, b, valor);
        setpoint(-y+xc, -x+yc, r, g, b, valor);
        setpoint(-y+xc, x+yc, r, g, b, valor);
        setpoint(-x+xc, y+yc, r, g, b, valor);
    }
} /*ponto_circulo*/

//Inspirado em https://marciobueno.com/arquivos/ensino/cg/CG_03_Primitivas_Graficas.pdf
// Option 1 = circulo completo
// Option 2 = semi circulo esquerdo
// Option 3 = semi circulo direito
void Bresenham::bresenhamCirculo(int raio, int valor,int xc,int yc,int option, float r, float g, float b){
    int x = 0 ;
    int y = raio;
    double d = 1.25 - raio;
    ponto_circulo(x,y,valor,xc,yc,option, r, g, b);
    while(y > x){
        if (d < 0) /* escolhe E */
            d += 2.0*x + 3.0;
        else { /* escolhe SE */
            d += 2*(x-y) + 5;
            y--;
        }
        x++;
        ponto_circulo(x,y,valor,xc,yc,option, r, g, b);
    } /* while*/
} /*pontomedio*/

void Bresenham::bresenham(GLfloat x1, GLfloat x2,GLfloat y1, GLfloat y2, float r, float g, float b, int line){
    glLineWidth(line);
    glColor3f(r, g, b);
    GLfloat dx,dy,incE,incNE,d;
    int x,y,i;
    dx = x2-x1;
    dy = y2-y1;
    d = (2*dy)-dx;
    incE = 2*dy;
    incNE = 2*(dy-dx);
    x = x1;
    y = y1;
    setpoint(x, y, r, g, b, line);
    if(dx == 0){
        for(i=y1;i<=y2;i++) setpoint(x, i, r, g, b, line);
    }else if(dy == 0){
        for(i=x1;i<=x2;i++) setpoint(i, y, r, g, b, line);
    }else{
        while(x <= x2){
            if(d <= 0){
                d += incE;
                x = x + 1;
            }else{
                d += incNE;
                x = x + 1;
                y = y + 1;
            }
            setpoint(x, y, r, g, b, line);
        }
    }
}

void Bresenham::displayBresenham(float r, float g, float b, int line){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(line);
    glColor3f(r, g, b);

    //Inspirado em http://professor.unisinos.br/ltonietto/jed/cgr/IntroOpenGL.pdf
    //Circulo do meio da quadra
    float circle_points = 1000;
    float angle = 0;
//    float angle1 = 0;
    float xstep = 384.0f;
    float ystep = 300.0f;
    float radio = 36.0f;
//    int i;
    bresenhamCirculo(radio,line,xstep,ystep,1, r, g, b);

    //Semicirculo esquerdo maior
    bresenham(100,142,420,420, r, g, b, line);
    bresenham(100,142,180,180, r, g, b, line);
    circle_points = 1000;
    angle = 0;
    xstep = 141.0f;
    ystep = 300.0f;
    radio = 120.0f;
    bresenhamCirculo(radio,line,xstep,ystep,3, r, g, b);

    //Semicirculo direito maior
    bresenham(626,668,420,420, r, g, b, line);
    bresenham(626,668,180,180, r, g, b, line);
    circle_points = 1000;
    angle = 0;
    xstep = 626.0f;
    ystep = 300.0f;
    radio = 120.0f;
    bresenhamCirculo(radio,line,xstep,ystep,2, r, g, b);

    //Ret‚ngulo esquerdo
    bresenham(100,100,336,264, r, g, b, line);
    bresenham(100,214,336,336, r, g, b, line);
    bresenham(214,214,336,264, r, g, b, line);
    bresenham(100,214,264,264, r, g, b, line);

    //Semicirculo esquerdo menor
    circle_points = 1000;
    angle = 0;
    xstep = 214.0f;
    ystep = 300.0f;
    radio = 36.0f;
    bresenhamCirculo(radio,line,xstep,ystep,3, r, g, b);

    //Ret‚ngulo direito
    bresenham(554,554,336,264, r, g, b, line);
    bresenham(668,668,336,264, r, g, b, line);
    bresenham(554,668,336,336, r, g, b, line);
    bresenham(554,668,264,264, r, g, b, line);

    //Semicirculo direito menor
    circle_points = 1000;
    angle = 0;
    xstep = 554.0f;
    ystep = 300.0f;
    radio = 36.0f;
    bresenhamCirculo(radio,line,xstep,ystep,2, r, g, b);

    //Linhas que representam a quadra
    bresenham(100,100,150,450, r, g, b, line);
    bresenham(668,668,150,450, r, g, b, line);
    bresenham(100,668,450,450, r, g, b, line);
    bresenham(100,668,150,150, r, g, b, line);

    //Linha que representa o centro da quadra
    bresenham(384,384,150,450, r, g, b, line);
    glFlush();
}
