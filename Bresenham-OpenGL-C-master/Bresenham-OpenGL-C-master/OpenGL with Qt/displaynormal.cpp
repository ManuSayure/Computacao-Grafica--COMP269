#include "displaynormal.h"
#include <algorithm>
#include <GLUT/glut.h>
#include <QtMath>
#define PI 3.1415926535898

using namespace std;

void DisplayNormal::setLine(int x1, int x2, int y1, int y2, int line, float r, float g, float b)
{
    glBegin(GL_LINES);
        glLineWidth(line);
        glColor3f(r, g, b);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
    glEnd();

    glFlush();
}

void DisplayNormal::displayNormal(float r, float g, float b, int line)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(line);
    glColor3f(r, g, b);

    //Inspirado em http://professor.unisinos.br/ltonietto/jed/cgr/IntroOpenGL.pdf
    //Circulo do meio da quadra
    float circle_points = 1000;
    float angle = 0;
    float xstep = 384.0f;
    float ystep = 300.0f;
    float radio = 36.0f;
    int i;
    glBegin(GL_LINE_LOOP);
    glLineWidth(line);
    glColor3f(r, g, b);
    for (i = 0; i < circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2i((cos(angle)*radio)+xstep, (sin(angle)*radio)+ystep);
    }
    glEnd();

    //Semicirculo esquerdo maior
    setLine(142,100,420,420,line, r, g, b);
    setLine(100,142,180,180,line, r, g, b);

    circle_points = 1000;
    angle = 0;
    xstep = 141.0f;
    ystep = 300.0f;
    radio = 120.0f;
    glBegin(GL_LINE_LOOP);
    glLineWidth(line);
    glColor3f(r, g, b);
    for (i = (-1)*(circle_points/4) ; i < circle_points/4 ; i++) {
        angle = (2*PI*i/circle_points);
        glVertex2i((cos(angle)*radio)+xstep, (sin(angle)*radio)+ystep);
    }
    glEnd();

    //Semicirculo direito maior
    setLine(626,668,420,420,line, r, g, b);
    setLine(626,668,180,180,line, r, g, b);

    circle_points = 1000;
    angle = 0;
    xstep = 626.0f;
    ystep = 300.0f;
    radio = 120.0f;
    glBegin(GL_LINE_LOOP);
    glLineWidth(line);
    glColor3f(r, g, b);
    for (i = 3*(circle_points/4); i > circle_points/4; i--) {
        angle = (2*PI*i/circle_points);
        glVertex2i((cos(angle)*radio)+xstep, (sin(angle)*radio)+ystep);
    }
    glEnd();

    //Ret‚ngulo esquerdo
    setLine(100,100,336,264,line, r, g, b);
    setLine(100,214,336,336,line, r, g, b);
    setLine(214,214,336,264,line, r, g, b);
    setLine(214,100,264,264,line, r, g, b);

    //Semicirculo esquerdo menor
    circle_points = 1000;
    angle = 0;
    xstep = 214.0f;
    ystep = 300.0f;
    radio = 36.0f;
    glBegin(GL_LINE_LOOP);
    glLineWidth(line);
    glColor3f(r, g, b);
    for (i = (-1)*(circle_points/4); i < circle_points/4; i++) {
        angle = (2*PI*i/circle_points);
        glVertex2i((cos(angle)*radio)+xstep, (sin(angle)*radio)+ystep);
    }
    glEnd();

    //Ret‚ngulo direito
    setLine(554,554,336,264,line, r, g, b);
    setLine(668,668,336,264,line, r, g, b);
    setLine(554,668,336,336,line, r, g, b);
    setLine(554,668,264,264,line, r, g, b);

    //Semicirculo direito menor
    circle_points = 1000;
    angle = 0;
    xstep = 554.0f;
    ystep = 300.0f;
    radio = 36.0f;
    glBegin(GL_LINE_LOOP);
    glLineWidth(line);
    glColor3f(r, g, b);
    for (i = 3*(circle_points/4); i > circle_points/4; i--) {
        angle = (2*PI*i/circle_points);
        glVertex2i((cos(angle)*radio)+xstep, (sin(angle)*radio)+ystep);
    }
    glEnd();


    //Linhas que representam a quadra
    setLine(100,100,150,450,line, r, g, b);
    setLine(668,668,150,450,line, r, g, b);
    setLine(100,668,450,450,line, r, g, b);
    setLine(100,668,150,150,line, r, g, b);

    //Linha que representa o centro da quadra
    setLine(384,384,150,450,line, r, g, b);

    glFlush();
}
