#include "PoliceCar.h"
#include "Cube.h"

PoliceCar::PoliceCar(point startPoint, point endPoint, double angle, color carColor, float stepsInc):Car(startPoint, endPoint, angle, carColor, stepsInc){}

PoliceCar::drawPolice()
{
    // Light values
    float shiny   =   1;  // Shininess (value)

    int at0 = 100;      //  Constant  attenuation %
    int at1 = 20;        //  Linear    attenuation %
    int at2 = 20;        //  Quadratic attenuation %

    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};

    //  Set specular color to white
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

   float cr = 0.1;
   float cb = 0.1;
   float cg = 0.1;

   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(startPoint.x,startPoint.y,startPoint.z);
   glRotated(angle,0,1,0);
   glScaled(endPoint.x,endPoint.y,endPoint.z);

   glPolygonOffset(1,1);

   drawWheel();

   glColor3f(cr, cb, cg);

   drawBody();

   glColor3f(cr, cb, cg);

   drawBumper();

   glColor3f(cr, cb, cg);
    drawPanels();

   glBindTexture(GL_TEXTURE_2D,5);

   glColor3f(0.8, 0.8, 1);

   drawWindshield();

   drawRearWindow();

   float t = glutGet(GLUT_ELAPSED_TIME)/1000.0;

   //Light bar

   //Mid section
   glColor3f(0.1, 0.1, 0.1);
   point startPoint{-0.2,0.42,0};
   point endPoint{0.07, 0.02, 0.05};

   Cube midSectionCube(startPoint, endPoint, 5, 0, 1);
   midSectionCube.draw();

   //  Enable light 1 - Police Light
   glEnable(GL_LIGHT1);

   if ((int)(t/0.5) % 2 == 0) {
      float amb[4] = {0,0,0,0};
      float dif[4] = {0.8,0,0,1};
      float spec[4] = {0,0,0,1};
      float pos[4] = {-0.2,0.26,-0.15,1.0};
      //Red Light
      glLightfv(GL_LIGHT1,GL_AMBIENT ,amb);
      glLightfv(GL_LIGHT1,GL_DIFFUSE ,dif);
      glLightfv(GL_LIGHT1,GL_SPECULAR,spec);
      glLightfv(GL_LIGHT1,GL_POSITION,pos);

      glLightf(GL_LIGHT1,GL_CONSTANT_ATTENUATION ,at0/100.0);
      glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION   ,at1/100.0);
      glLightf(GL_LIGHT1,GL_QUADRATIC_ATTENUATION,at2/100.0);

       //Red Light
       float redEm[4] = {0.8, 0, 0, 1.0};
       glMaterialf(GL_FRONT,GL_SHININESS,0);
       glMaterialfv(GL_FRONT,GL_SPECULAR,redEm);
       glMaterialfv(GL_FRONT,GL_EMISSION,redEm);
       glColor3f(0.5, 0, 0);
       startPoint.z = -0.15;
       endPoint.z = 0.1;
       Cube redLightCube(startPoint, endPoint, 5, 0, 1);
       redLightCube.draw();

       //Blue Light
       glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
       glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
       glColor3f(0, 0, 0.5);
       glColor3f(0.1, 0.1, 0.1);

       startPoint.z = 0.15;
       Cube blueLightCube(startPoint, endPoint, 5, 0, 1);
       blueLightCube.draw();
   } else {
       float amb[4] = {0,0,0,0};
       float dif[4] = {0,0,0.8,1};
       float spec[4] = {0,0,0,1};
       float pos[4] = {-0.2,0.26,0.15,1.0};

       //Blue Light
       glLightfv(GL_LIGHT1,GL_AMBIENT ,amb);
       glLightfv(GL_LIGHT1,GL_DIFFUSE ,dif);
       glLightfv(GL_LIGHT1,GL_SPECULAR,spec);
       glLightfv(GL_LIGHT1,GL_POSITION,pos);

       glLightf(GL_LIGHT1,GL_CONSTANT_ATTENUATION ,at0/100.0);
       glLightf(GL_LIGHT1,GL_LINEAR_ATTENUATION   ,at1/100.0);
       glLightf(GL_LIGHT1,GL_QUADRATIC_ATTENUATION,at2/100.0);

       //Red Light
       glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
       glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
       glColor3f(0.5, 0, 0);
       startPoint.z = -0.15;
       endPoint.z = 0.1;
       Cube redLightCube(startPoint, endPoint, 5, 0, 1);
       redLightCube.draw();

       //Blue Light
       float blueEm[4] = {0, 0, 0.8, 1.0};
       glMaterialf(GL_FRONT,GL_SHININESS,0);
       glMaterialfv(GL_FRONT,GL_SPECULAR,blueEm);
       glMaterialfv(GL_FRONT,GL_EMISSION,blueEm);
       glColor3f(0, 0, 0.5);
       startPoint.z = 0.15;
       Cube blueLightCube(startPoint, endPoint, 5, 0, 1);
       blueLightCube.draw();
   }

   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

   //Undo transformations
   glPopMatrix();
}
