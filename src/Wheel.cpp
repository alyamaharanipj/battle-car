#include "Wheel.h"
#include <math.h>

Wheel::Wheel(point startPoint, point endPoint, double angle, int d, int s)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->angle = angle;
    this->d = d;
    this->s = s;
}

void Wheel::setStartPoint(point startPoint)
{
    this->startPoint = startPoint;
}

void Wheel::setEndPoint(point endPoint)
{
    this->endPoint = endPoint;
}

void Wheel::setPoint(point startPoint, point endPoint)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

void Wheel::setAngle(double angle)
{
    this->angle = angle;
}

void Wheel::setD(int d)
{
    this->d = d;
}

void Wheel::setS(int s)
{
    this->s = s;
}

void Wheel::draw()
{
    //  Set specular color to white
   float white[] = {1,1,1,1};
   float black[] = {0,0,0,1};

   //Turn off shininess for the rubber tire
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,0);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(startPoint.x, startPoint.y, startPoint.z);
   glRotated(angle,0,1,0);
   glScaled(endPoint.x,endPoint.y,endPoint.z);

   glBindTexture(GL_TEXTURE_2D,11);

   glColor3f(0.8,0.8,0.8);

   //Tire
   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0, 0, -1);
   glTexCoord2f(0.5, 0.5);
   glVertex3f(0, 0, -0.05);
   for (angle = 0; angle <= 360; angle += s)
   {
      double ph = d - 90;
      glTexCoord2f(0.5 * Cos(angle) + 0.5, 0.5 * Sin(angle) + 0.5);
      glVertex3d(Sin(angle)* Cos(ph), Cos(angle)* Cos(ph), -0.05);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0, 0, 1);
   glTexCoord2f(0.5, 0.5);
   glVertex3f(0, 0, 0.05);
   for (angle = 360; angle >= 0; angle -= s)
   {
      double ph = d-90;
      glTexCoord2f(0.5*Cos(angle)+0.5,0.5*Sin(angle)+0.5);
      glVertex3d(Sin(angle)*Cos(ph), Cos(angle)*Cos(ph), 0.05);
   }
   glEnd();

   glBindTexture(GL_TEXTURE_2D,24);

   glColor3f(0.5,0.5,0.55);
   glBegin(GL_QUAD_STRIP);
   for (angle = 0; angle <= 360; angle += s)
   {
      double ph = d - 90;
      glNormal3f(Sin(angle) * Cos(ph), Cos(angle) * Cos(ph), 0);
      glTexCoord2f(0, 0.1 * angle); glVertex3d(Sin(angle) * Cos(ph), Cos(angle) * Cos(ph), -0.05);
      glTexCoord2f(1, 0.1 * angle); glVertex3d(Sin(angle) * Cos(ph), Cos(angle) * Cos(ph), 0.05);
   }
   glEnd();

   //  Undo transformations
   glPopMatrix();
}
