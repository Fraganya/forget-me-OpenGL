#include <GL/gl.h>
#include <GL/glut.h>

void display(){
    //clear window
    glClear(GL_COLOR_BUFFER_BIT);

    //draw scene
    glutSolidTeapot(.5);

    //flush drawing resolution to window
    glFlush();
}

int main(int argc,char * argv[]){
    //initialize GLUT with cmd params
    glutInit(&argc,argv);

    //setup - size, position and display mode for new windows
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    //create and setup window
    glutCreateWindow("Hello Teapot");
    glutDisplayFunc(display);

    //tell GLUT to wait for events
    glutMainLoop();
}
