#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

float angle = 0.0f;

void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //reset the transformations
    glLoadIdentity();

    gluLookAt(
              0.0f,0.0f,10.0f,
              0.0f,0.0f,0.0f,
              0.0f,1.0f,0.0f
    );

    glRotatef(angle,0.0f,1.0f,0.0f);

    glBegin(GL_TRIANGLES);
        glVertex3f(-2.0f,-2.0f,0.0f);
        glVertex3f(2.0f,0.0f,0.0f);
        glVertex3f(0.0f,2.0f,0.0f);

    glEnd();

    angle+=0.1f;

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
    gluPerspective(45.0f,ratio,0.1f,100.0f);

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
    glutIdleFunc(renderScene);

    glutMainLoop();
}
