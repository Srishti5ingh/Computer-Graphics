#include <GL/glfw.h>
#include <GL/glu.h>
#include<math.h>

float x = 0.05;

//float cubeSize = 0.5;
void snowman();
void snowfall();
void DrawCircle(float);
void DisplayFaces();

GLUquadricObj *quadric;
    float radius = 0.40f;

    int slices = 25, stacks = 25;
int main()
{
    int width = 900, height = 800;
    double y1 = 1.0,y2=0.8;

    glfwInit();
    glfwOpenWindow( width, height, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
    glfwSetWindowTitle("Snowman");
    quadric = gluNewQuadric();

    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

    /*
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 65.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f );
    */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //
    while(true)
    {
  double a=60;

   glClearColor(0.3,0.5,0.7,0);

        glClear(GL_COLOR_BUFFER_BIT);
        gluQuadricDrawStyle(quadric, GLU_SMOOTH);

        DisplayFaces();
        glPushMatrix();
      // glRotatef(a,0.0,0.0,1.0);
        //a+=0.005;
        snowman();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.8,y1,0.0);
        snowfall();
        glPopMatrix();
        y1-=0.001;

        glPushMatrix();
        glTranslatef(0.8,y1,0.0);
        snowfall();
        glPopMatrix();
        y1-=0.0001;

        glPushMatrix();
        glTranslatef(-0.6,y2,0.0);
        snowfall();
        glPopMatrix();
        y2-=0.0003;

        glPushMatrix();
        glTranslatef(0.6,y2,0.0);
        snowfall();
        glPopMatrix();
        y2-=0.0005;
        if(y2==0)
        {
            y2=0.8;
        }



        //drawunitcube();

        glfwSwapBuffers();
        if(glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
            break;
    }
    gluDeleteQuadric(quadric);
    glfwCloseWindow();
    glfwTerminate();

    return 0;
}
void snowfall()
{
    glBegin(GL_QUADS);


        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
        gluSphere(quadric, 0.05, slices, stacks);


}

void snowman()
{
    glBegin(GL_QUADS);


        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
        gluSphere(quadric, radius-0.05, slices, stacks);
        glRotatef(0.005,1.0f,0.0f,1.0f);


      //head
        glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, radius+0.07, 0.0);
    gluSphere(quadric, radius-0.2, slices, stacks);
    //glRotatef(0.005,1.0f,0.0f,1.0f);
    glPopMatrix();

  /*//eye
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(-0.5,radius+3,+5.0);
    gluSphere(quadric, 0.04, slices, stacks);
    //glPopMatrix();


     //glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(-0.2,radius+0.2,0.8);
    gluSphere(quadric, 0.04, slices, stacks);
    glPopMatrix();
    */


        glPushMatrix();
        glColor3f(0.0, 0.0, 1.0);
        glTranslatef(-0.08,radius+0.15,0.8);
        DrawCircle(0.2);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.0, 1.0);
        glTranslatef(0.08,radius+0.15,0.8);
        DrawCircle(0.2);
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.0,radius+0.05,0.8);
        DrawCircle(0.2);
        glPopMatrix();
glEnd();
}


 void DrawCircle(float radius) {
    double pi = 3.14159/180;
    int s_deg = 0;
    int e_deg = 360;
    glBegin(GL_LINE_LOOP);

    for (int angle = s_deg; angle < e_deg; angle = angle + 1) {
        glVertex2d((radius/8 )* sin((float)angle * pi), (radius/8) * cos((float)angle * pi));
    }
    glEnd();
 }

 void DisplayFaces() {
    if(glfwGetKey(GLFW_KEY_KP_1) == GLFW_PRESS) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
gluLookAt(0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    else if(glfwGetKey(GLFW_KEY_KP_2) == GLFW_PRESS) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glTranslatef(0.7,0.0,0.0);
        snowman();

        //gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
     else if(glfwGetKey(GLFW_KEY_KP_3) == GLFW_PRESS) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glTranslatef(-0.7,0.0,0.0);
        snowman();

        //gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }

 }
