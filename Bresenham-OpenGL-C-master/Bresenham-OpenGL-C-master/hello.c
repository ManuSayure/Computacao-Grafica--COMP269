#include <GL/glut.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1415926535898

int choice, line=0;
float r,g,b;

void setline(x1,x2,y1,y2,line){
	glBegin(GL_LINES);
	glLineWidth(line);
	glColor3f(r, g, b);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();	
}

void setpoint(x,y,line){
	glPointSize(line);
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i(x, y);
	glEnd();	
}
	
void displayNormal(void) { 
	glClear(GL_COLOR_BUFFER_BIT); 
	glLineWidth(line);
	glColor3f(r, g, b);
	
	//Inspirado em http://professor.unisinos.br/ltonietto/jed/cgr/IntroOpenGL.pdf
	//Circulo do meio da quadra
	GLfloat circle_points = 1000;
	GLfloat angle = 0; 
	GLfloat xstep = 384.0f;
	GLfloat ystep = 300.0f;
	GLfloat radio = 36.0f;
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
	setline(142,100,420,420,line);
	setline(100,142,180,180,line);
	
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
	setline(626,668,420,420,line);
	setline(626,668,180,180,line);
	
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
	
	//Retângulo esquerdo
	setline(100,100,336,264,line);
	setline(100,214,336,336,line);
	setline(214,214,336,264,line);
	setline(214,100,264,264,line);
	
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
	
	//Retângulo direito	
	setline(554,554,336,264,line);
	setline(668,668,336,264,line);
	setline(554,668,336,336,line);
	setline(554,668,264,264,line);
	
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
	setline(100,100,150,450,line);
	setline(668,668,150,450,line);
	setline(100,668,450,450,line);
	setline(100,668,150,150,line);
	
	//Linha que representa o centro da quadra
	setline(384,384,150,450,line);
	
	glFlush(); 
}

//Inspirado em https://marciobueno.com/arquivos/ensino/cg/CG_03_Primitivas_Graficas.pdf
// Option 1 = circulo completo
// Option 2 = semi circulo esquerdo
// Option 3 = semi circulo direito
void ponto_circulo(int x, int y, int valor, int xc, int yc,int option)
{
	//Circulo completo ou semi circulo direito
	if(option != 2){
		setpoint(x+xc, y+yc, valor);
		setpoint(y+xc, x+yc, valor);
		setpoint(y+xc, -x+yc, valor);
		setpoint(x+xc,-y +yc, valor);		
	}
	//Circulo completo ou semi circulo esquerdo
	if(option != 3){
		setpoint(-x+xc, -y+yc, valor);
		setpoint(-y+xc, -x+yc, valor);
		setpoint(-y+xc, x+yc, valor);
		setpoint(-x+xc, y+yc, valor);		
	}
} /*ponto_circulo*/

//Inspirado em https://marciobueno.com/arquivos/ensino/cg/CG_03_Primitivas_Graficas.pdf
// Option 1 = circulo completo
// Option 2 = semi circulo esquerdo
// Option 3 = semi circulo direito
void bresenhamCirculo(int raio, int valor,int xc,int yc,int option){
	int x = 0 ;
	int y = raio;
	double d = 1.25 - raio;
	ponto_circulo(x,y,valor,xc,yc,option);
	while(y > x){
		if (d < 0) /* escolhe E */
			d += 2.0*x + 3.0;
		else { /* escolhe SE */
			d += 2*(x-y) + 5;
			y--;
		}
		x++;
		ponto_circulo(x,y,valor,xc,yc,option);
	} /* while*/
} /*pontomedio*/

void bresenham(GLfloat x1, GLfloat x2,GLfloat y1, GLfloat y2){
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
	setpoint(x,y,line);
	if(dx == 0){
		for(i=y1;i<=y2;i++) setpoint(x,i,line);
	}else if(dy == 0){
		for(i=x1;i<=x2;i++) setpoint(i,y,line);
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
			setpoint(x,y,line);
		}
	}
}

void displayBresenham(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	glLineWidth(line);
	glColor3f(r, g, b);
	
	//Inspirado em http://professor.unisinos.br/ltonietto/jed/cgr/IntroOpenGL.pdf
	//Circulo do meio da quadra
	GLfloat circle_points = 1000;
	GLfloat angle = 0; 
	GLfloat angle1 = 0; 
	GLfloat xstep = 384.0f;
	GLfloat ystep = 300.0f;
	GLfloat radio = 36.0f;
	int i;
	bresenhamCirculo(radio,line,xstep,ystep,1);
	
	//Semicirculo esquerdo maior 
	bresenham(100,142,420,420);
	bresenham(100,142,180,180);	
	circle_points = 1000;
	angle = 0; 
	xstep = 141.0f;
	ystep = 300.0f;
	radio = 120.0f;
	bresenhamCirculo(radio,line,xstep,ystep,3);
	
	//Semicirculo direito maior
	bresenham(626,668,420,420);
	bresenham(626,668,180,180);	
	circle_points = 1000;
	angle = 0; 
	xstep = 626.0f;
	ystep = 300.0f;
	radio = 120.0f;
	bresenhamCirculo(radio,line,xstep,ystep,2);
	
	//Retângulo esquerdo
	bresenham(100,100,336,264);
	bresenham(100,214,336,336);
	bresenham(214,214,336,264);
	bresenham(100,214,264,264);
	
	//Semicirculo esquerdo menor	
	circle_points = 1000;
	angle = 0; 
	xstep = 214.0f;
	ystep = 300.0f;
	radio = 36.0f;
	bresenhamCirculo(radio,line,xstep,ystep,3);
	
	//Retângulo direito	
	bresenham(554,554,336,264);
	bresenham(668,668,336,264);
	bresenham(554,668,336,336);
	bresenham(554,668,264,264);
	
	//Semicirculo direito menor	
	circle_points = 1000;
	angle = 0; 
	xstep = 554.0f;
	ystep = 300.0f;
	radio = 36.0f;	
	bresenhamCirculo(radio,line,xstep,ystep,2);
		
	//Linhas que representam a quadra
	bresenham(100,100,150,450);
	bresenham(668,668,150,450);
	bresenham(100,668,450,450);
	bresenham(100,668,150,150);
	
	//Linha que representa o centro da quadra
	bresenham(384,384,150,450);	
	glFlush(); 	
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, 760, 0, 600);
}

int main(int argc, char **argv) {
	
	printf("Cor da linha:\n");
	printf("R: ");
	scanf("%f",&r);
	printf("G: ");
	scanf("%f",&g);
	printf("B: ");
	scanf("%f",&b);
	
	printf("\nEspessura da linha:");
	scanf("%d",&line);
	
	
	printf("\nDigite 1 para tecnica normal e 2 para Bresenham\n");
	scanf("%d",&choice);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(760, 600);
	glutCreateWindow("CG task 01");
	init();
	if(choice == 1){
		glutDisplayFunc(displayNormal);		
	}else{
		glutDisplayFunc(displayBresenham);			
	}
	glutMainLoop();
	return 0;
}

