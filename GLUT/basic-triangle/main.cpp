#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>


void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        //glVertex3f(-0.5,-0.5,0.0);
       // glVertex3f(0.5,0.0,0.0);
        //glVertex3f(0.0,0.5,0.0);

         glVertex3f(-2,-2,-5.0);
        glVertex3f(2.0,0.0,-5.0);
        glVertex3f(0.0,2.0,-5.0);

    glEnd();

    glutSwapBuffers();
}

void reshape(int width,int height){
    if(height == 0 ){
        height =1;
    }

    float ratio = (1.0*width)/height;

    //use the projection perspective
    glMatrixMode(GL_PROJECTION);

    //reset the matrix
    glLoadIdentity();

    //set the viewport to the entire window
    glViewport(0,0,width,height);

    //set the correct perspective
    gluPerspective(45,ratio,1,1000);

    //get back to the modelview
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc,char * argv[]){
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);

    glutCreateWindow("GL Triangles");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);

    glutMainLoop();
}
