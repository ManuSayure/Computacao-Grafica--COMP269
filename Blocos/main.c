#include <GL/glut.h>
#include "blocos.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("blocos");

    init();

    glutDisplayFunc(displayFnc);
    glutTimerFunc(200, blocks_doFrame, 0);

    glutMainLoop();

	return 0;
}
