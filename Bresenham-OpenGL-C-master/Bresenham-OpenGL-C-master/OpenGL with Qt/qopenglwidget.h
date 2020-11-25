#ifndef QOPENGLGLWIDGET_H
#define QOPENGLGLWIDGET_H

#include <QGLWidget>
#include <GLUT/glut.h>
#include <QTimer>
#include <algorithm>


extern float rgb[3];
extern int tamanho;
extern int algNormalOuBresenham;
extern bool limparTela;
extern bool desfazer;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QTimer timer;
    int xAtPress, yAtPress;
    std::vector<std::pair<int,int> > firstPoint;
    std::vector<std::pair<int,int> > secondPoint;
    bool firstClick;
};

#endif // QOPENGLGLWIDGET_H
