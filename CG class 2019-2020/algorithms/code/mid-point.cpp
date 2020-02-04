/**
* Program : mid-point.cpp
*/

#include <GL/glut.h>

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void generateByMidPoint(int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
    {
        generateByMidPoint(x2, y2, x1, y1);
        return;
    }

    int slope;
    int dx, dy, d, x, y;

    dx = x2 - x1;
    dy = y2 - y1;
    d = dx - 2 * dy;
    y = y1;

    if (dy < 0) {
        slope = -1;
        dy = -dy;
    }
    else {
        slope = 1;
    }

    for (x = x1; x < x2; x++) {
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        if (d <= 0) {
            d += 2 * dx - 2 * dy;
            y += slope;
        }
        else {
            d += -2 * dy;
        }
        glEnd();
    }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0,1.0, 1.0);
    generateByMidPoint(100, 200, 400, 200);

    // notice the aliasing effect as well
    generateByMidPoint(100, 200, 400, 400);


    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Line generation using midpoint LGA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
