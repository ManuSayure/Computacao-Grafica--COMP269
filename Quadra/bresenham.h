#ifndef BRESENHAM_H
#define BRESENHAM_H

class Bresenham {

public:
    void setpoint(int x,int y, float r, float g, float b, int line);

    void ponto_circulo(int x, int y, int valor, int xc, int yc,int option, float r, float g, float b);

    void bresenhamCirculo(int raio, int valor,int xc,int yc,int option, float r, float g, float b);

    void bresenham(float x1, float x2, float y1, float y2, float r, float g, float b, int line);

    void displayBresenham(float r, float g, float b, int line);

};

#endif // BRESENHAM_H
