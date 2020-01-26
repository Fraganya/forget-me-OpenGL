#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

//angle of rotation for the camera
float angle = 0.0f;

//vector representing the camera
float lx=0.0f,lz=1.0f;

float x=0.0f,z=5.0f;


void drawSnowMan(){
    glColor3f(1.0f,1.0f,1.0f);

    //draw body
    glTranslatef(0.0f,0.75f,0.0f);
    glutSolidSphere(0.75f,20,20);

    //draw head
    glTranslatef(0.0f,1.0f,0.0f);
    glutSolidSphere(0.25f,20,20);

    //draw eyes
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glTranslatef(0.05f,0.10f,0.18f);
    glutSolidSphere(0.05f,10,10);
    glTranslatef(-0.1f,0.0f,0.0f);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();

    //draw nose
    glColor3f(1.0f,0.5f,0.5f);
    glutSolidCone(0.08f,0.5f,10,2);
}



float red = 1.0f, green = 1.0f, blue =1.0f;

void processNormalKeys(unsigned char key, int x, int y){
    if( key == 27){
        exit(0);
    }
    else if(key == 'r'){
        int mod = glutGetModifiers();

        if(mod == GLUT_ACTIVE_ALT){
            red = 0.0;
        }
        else{
            red = 1.0;
        }
    }
}

void processSpecialKeys(int key,int xx , int yy){
    float fraction = 0.1f;

    switch(key){
        case GLUT_KEY_LEFT:
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT:
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP:
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN:
            x -= lx * fraction;
            z -= lz * fraction;
    }
}

void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //reset the transformations
    glLoadIdentity();

    /**
    * The gluLookAt enables setting the camera position and orientation
    * it has 3 groups of params:
    *   - first 3 indicate the position of the camera
    *    - next 3 indicate the position we are looking at. any point on our line of sight
    *    - last 3 indicates the up vector usually set to (0.0,-1.0,0.0)
    */
    gluLookAt(
              x,1.0f,z,
              x+lx,1.0f,z+lz,
              0.0f,1.0f,0.0f
    );

    glColor3f(0.9f,0.9f,0.9f);
    glBegin(GL_QUADS);
        glVertex3f(-100.0f,0.0f,-100.0f);
        glVertex3f(-100.0f,0.0f,100.0f);
        glVertex3f(100.0f,0.0f,100.0f);
        glVertex3f(100.0f,0.0f,-100.0f);
    glEnd();

    // draw 36 snow men
    for(int outerPos=-3;outerPos<3;outerPos++){
        for(int innerPos=-3;innerPos<3;innerPos++){
            glPushMatrix();
            glTranslatef(outerPos*10.0,0,innerPos*10.0);
            drawSnowMan();
            glPopMatrix();
        }

    }
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

    glutCreateWindow("Snowman Camera");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
