#include "qopenglwidget.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <vector>
#include <utility>
#include <bresenham.h>
#include <displaynormal.h>
#include <stdlib.h>

#define HEIGHT 400
#define WIDTH 600
#define DISPLAYNORMAL 0
#define BRESENHAM 1

DisplayNormal normal;
Bresenham bresenham;

float rgb[3] = {0,0,0};
int tamanho = 1, _x, _y;
int algNormalOuBresenham = DISPLAYNORMAL;
bool limparTela = false, desfazer = false;


GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(50);
}

void GLWidget::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glViewport(0, 0, WIDTH, HEIGHT);
    firstClick = true;
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(rgb[0], rgb[1], rgb[2]);
    glPointSize(tamanho);
    glLineWidth(tamanho);

    if(desfazer){
        desfazer = false;
        if(firstPoint.size()>=1){
            if(firstClick){
                firstPoint.pop_back();
                secondPoint.pop_back();
            } else {
                firstClick = true;
                firstPoint.pop_back();
            }
        }
    }

    if(limparTela){
        limparTela = false;
        if(firstClick){
            firstPoint.clear();
            secondPoint.clear();
        } else {
            firstClick = true;
            firstPoint.clear();
            secondPoint.clear();
        }
    }

    if(!firstClick){
        if(algNormalOuBresenham == DISPLAYNORMAL)
            normal.setLine(firstPoint[firstPoint.size()-1].first,_x, firstPoint[firstPoint.size()-1].second,_y, tamanho, rgb[0], rgb[1], rgb[2]);
        else
            bresenham.bresenham(firstPoint[firstPoint.size()-1].first,_x, firstPoint[firstPoint.size()-1].second,_y, rgb[0], rgb[1], rgb[2], tamanho);
    }

    if(algNormalOuBresenham == DISPLAYNORMAL){
        normal.displayNormal(rgb[0], rgb[1], rgb[2], tamanho);
        for(int i = 0; i < secondPoint.size(); i++ ){
            normal.setLine(firstPoint[i].first,secondPoint[i].first, firstPoint[i].second,secondPoint[i].second, tamanho, rgb[0], rgb[1], rgb[2]);
        }

    } else if (algNormalOuBresenham == BRESENHAM){
        bresenham.displayBresenham(rgb[0], rgb[1], rgb[2], tamanho);
        for(int i = 0; i < secondPoint.size(); i++ ){
            bresenham.bresenham(firstPoint[i].first,secondPoint[i].first, firstPoint[i].second,secondPoint[i].second, rgb[0], rgb[1], rgb[2], tamanho);
        }

    }
    glFlush();
}

void GLWidget::resizeGL(int w, int h){}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    std::pair<int,int> point;
    point.first = event->x();
    point.second = 399-event->y();
    if(firstClick) {
        firstPoint.push_back(point);
        firstClick = false;
    } else {
        secondPoint.push_back(point);
        firstClick = true;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event){
    _x = event->x();
    _y = 399-event->y();
}
