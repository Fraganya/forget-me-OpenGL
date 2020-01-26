#include <GL/gl.h>
#include <GL/glut.h>

void display(){
    //clear window
    glClear(GL_COLOR_BUFFER_BIT);

    // future matrix manipulations should affect the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    //draw scene
    //glutSolidTeapot(.4);
    glutWireTeapot(.5);

    //flush drawing resolution to window
    glFlush();
}

void reshape(int width,int height){
    //define the viewport transformation
    glViewport(0,0,width,height);
}

int main(int argc,char * argv[]){
    //initialize GLUT with cmd params
    glutInit(&argc,argv);

    //setup - size, position and display mode for new windows
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGB);

    //create and setup window
    glutCreateWindow("Hello Teapot");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    //define projection transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);

    //define the viewing transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

    //tell GLUT to wait for events
    glutMainLoop();
}
