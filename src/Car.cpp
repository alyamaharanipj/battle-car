#include "Car.h"
#include "Wheel.h"
#include "Cube.h"

Car::Car(point startPoint, point endPoint, double angle, color carColor, float stepsInc)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->angle = angle;
    this->carColor = carColor;
    this->steps = 0;
    this->stepsInc = stepsInc;
}

void Car::setStartPoint(point startPoint)
{
    this->startPoint = startPoint;
}

point Car::getStartPoint()
{
    return startPoint;
}

void Car::setEndPoint(point endPoint)
{
    this->endPoint = endPoint;
}

void Car::setPoint(point startPoint, point endPoint)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

void Car::setAngle(double angle)
{
    this->angle = angle;
}

void Car::addAngle()
{
    this->angle += 1;
}

void Car::decreaseAngle()
{
    this->angle -= 1;
}

void Car::setColor(color carColor)
{
    this->carColor = carColor;
}


void Car::moveRight()
{
    this->startPoint.x += stepsInc;
}

void Car::moveLeft()
{
    this->startPoint.x -= stepsInc;
}

void Car::moveBack()
{
    this->startPoint.z -= stepsInc;
}

void Car::moveFront()
{
    this->startPoint.z += stepsInc;
}

void Car::moveCar()
{
    this->startPoint.z += stepsInc;
    this->angle--;
}

double Car::getAngle()
{
    return angle;
}

float Car::getStepsInc()
{
    return stepsInc;
}

float Car::getSteps()
{
    return steps;
}

void Car::addSteps()
{
    this->steps += stepsInc;
}

void Car::resetStep()
{
    this->steps = 0;
}

void Car::setCollide(bool collide)
{
    this->collide = collide;
}

bool Car::isCollided()
{
    return collide;
}

void Car::decreaseSteps()
{
    this->steps -= stepsInc/10;
}

void Car::decreaseStepsInc()
{
    this->stepsInc -= 0.005;
}

void Car::increaseStepsInc()
{
    this->stepsInc += 0.005;
}

void Car::drawWheel()
{
   point wheelStartPoint{0.6, 0, 0.4};
   point wheelEndPoint{1, 1, 1};

   Wheel wheel(wheelStartPoint, wheelEndPoint, 0, 8, 10);
   wheel.draw();

   wheelStartPoint.x = -0.6;
   wheelStartPoint.z = -0.4;
   wheel.setStartPoint(wheelStartPoint);
   wheel.draw();

   wheelStartPoint.x = 0.6;
   wheel.setStartPoint(wheelStartPoint);
   wheel.draw();

   wheelStartPoint.x = -0.6;
   wheelStartPoint.z = 0.4;
   wheel.setStartPoint(wheelStartPoint);
   wheel.draw();
}

void Car::drawBody()
{
   point carBodyStartPoint{0, 0.1, 0};
   point carBodyEndPoint{0.8, 0.1, 0.4};

   //Lower Body
   Body body(carBodyStartPoint, carBodyEndPoint, 0, 0);
   body.draw();

   //Cabin
   carBodyStartPoint.x = -0.1;
   carBodyStartPoint.y = 0.3;
   carBodyEndPoint.x = 0.3;
   carBodyEndPoint.z = 0.35;

   body.setStartPoint(carBodyStartPoint);
   body.setEndPoint(carBodyEndPoint);
   body.setW(1);
   body.draw();
}

void Car::drawBumper()
{
   point bumperStartPoint{0.8, 0, 0};
   point bumperEndPoint{1,1,1};
   //Front Bumper
   Bumper bumper(bumperStartPoint, bumperEndPoint, 0, 1);
   bumper.draw();

   //Rear Bumper
   bumperStartPoint.x = -0.8;
   bumper.setStartPoint(bumperStartPoint);
   bumper.setAngle(180);
   bumper.setM(0);
   bumper.draw();
}

void Car::drawPanels()
{
   int shiny = 1;
   float white[] = {1,1,1,1};
   float black[] = {0,0,0,1};

   //  Set specular color to white
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

   glEnable(GL_POLYGON_OFFSET_FILL);

   glBindTexture(GL_TEXTURE_2D, 8);

   //Texture repetition values
   float texRepX = 1.0;
   float texRepY = 1.0;

   //Hood and upper side panels
   texRepX = endPoint.x;
   texRepY = endPoint.z;
   glBegin(GL_QUADS);
   glNormal3f(0, 0.707107, 0.707107);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.8, 0.25, 0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.8, 0.2, 0.4);
   glTexCoord2f(texRepX,texRepY); glVertex3f(0.8, 0.2, 0.4);
   glTexCoord2f(0.0,texRepY); glVertex3f(0.8, 0.25, 0.35);

   glNormal3f(0, 1, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(0.4, 0.25, 0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(0.8, 0.25, 0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(0.8, 0.25, -0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(0.4, 0.25, -0.35);

   glNormal3f(0, 0.707107, -0.707107);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.8, 0.2, -0.4);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.8, 0.25, -0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(0.8, 0.25, -0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(0.8, 0.2, -0.4);
   glEnd();
}

void Car::drawWindshield()
{

   glBindTexture(GL_TEXTURE_2D,6);
   //Windshield
   int texRepX = 1.0;
   int texRepY = 1.0;
   glBegin(GL_QUADS);
   glNormal3f(0.6, 0.8, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(0.4,0.25,0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(0.4,0.25,-0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(0.2,0.4,-0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(0.2,0.4,0.35);
   glEnd();

   glBegin(GL_TRIANGLES);
   glNormal3f(0,0,1);
   glTexCoord2f(0.0,0.0); glVertex3f(0.2,0.4,0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(0.2,0.25,0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(0.4,0.25,0.35);

   glNormal3f(0,0,-1);
   glTexCoord2f(0.0,0.0); glVertex3f(0.4,0.25,-0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(0.2,0.25,-0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(0.2,0.4,-0.35);
   glEnd();
}

void Car::drawRearWindow()
{
   glBindTexture(GL_TEXTURE_2D,6);
   //Rear Window
   int texRepX = 1.0;
   int texRepY = 1.0;
   glBegin(GL_QUADS);
   glNormal3f(-0.6, 0.8, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.6,0.25,-0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.6,0.25,0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.4,0.4,0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(-0.4,0.4,-0.35);
   glEnd();

   glBegin(GL_TRIANGLES);
   glNormal3f(0,0,1);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.6,0.25,0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(-0.4,0.25,0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(-0.4,0.4,0.35);

   glNormal3f(0,0,-1);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.4,0.4,-0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(-0.4,0.25,-0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(-0.6,0.25,-0.35);
   glEnd();

   int shiny = 1;

   float white[] = {1,1,1,1};
   float black[] = {0,0,0,1};
   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

}

void Car::draw()
{
    //  Set specular color to white
   float white[] = {1,1,1,1};
   float black[] = {0,0,0,1};

   // Light values
   float shiny   =   1;  // Shininess (value)

   glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(startPoint.x, startPoint.y, startPoint.z);
   glRotated(angle,0,1,0);
   glScaled(endPoint.x,endPoint.y,endPoint.z);

   glPolygonOffset(1,1);

   drawWheel();

   glColor3f(carColor.cr, carColor.cb, carColor.cg);

   drawBody();

   float texScale = 1.0;

   glColor3f(carColor.cr, carColor.cb, carColor.cg);

   drawBumper();

   glColor3f(carColor.cr, carColor.cb, carColor.cg);
   drawPanels();

   //Trunk
   int texRepX = endPoint.x/texScale;
   int texRepY = endPoint.z/texScale;
   glBegin(GL_QUADS);
   glNormal3f(0,1,0);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.8, 0.25, -0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.8, 0.25, 0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.6, 0.25, 0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(-0.6, 0.25, -0.35);
   glEnd();

   glBindTexture(GL_TEXTURE_2D, 6);

   glColor3f(0.8, 0.8, 1);

    drawWindshield();

   glBindTexture(GL_TEXTURE_2D, 6);
    drawRearWindow();

   //Spoiler
   glColor3f(0.3,0.3,0.3);

   point spoilerStartPoint{-0.75,0.28,0.3};
   point spoilerEndPoint{0.02,0.03,0.02};

   Cube spoiler(spoilerStartPoint, spoilerEndPoint, 26, 0, texScale);
   spoiler.draw();
   spoilerStartPoint.z = -0.3;
   spoiler.setStartPoint(spoilerStartPoint);

   texRepX = 5.0;
   texRepY = 1.0;

   glBegin(GL_QUADS);
   glNormal3f(0, -1, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.7,0.31,-0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.7,0.31,0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.8,0.31,0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(-0.8,0.31,-0.35);

   glNormal3f(0.196116, 0.980581, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.8,0.33,-0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.8,0.33,0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.7,0.31,0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(-0.7,0.31,-0.35);

   texRepX = 5.0;
   texRepY = 0.2;
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.8,0.33,0.35);
   glTexCoord2f(texRepX,0.0); glVertex3f(-0.8,0.33,-0.35);
   glTexCoord2f(texRepX,texRepY); glVertex3f(-0.8,0.31,-0.35);
   glTexCoord2f(0.0,texRepY); glVertex3f(-0.8,0.31,0.35);

   glEnd();

   glBindTexture(GL_TEXTURE_2D,8);
   glColor3f(carColor.cr, carColor.cb, carColor.cg);

   //Spoiler Fins
   texRepX = endPoint.x/texScale;
   texRepY = endPoint.y/texScale;
   glBegin(GL_TRIANGLES);
   glNormal3f(0,0,-1);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.68,0.31,-0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(-0.82,0.31,-0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(-0.82,0.35,-0.35);

   glNormal3f(0,0,1);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.82,0.35,0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(-0.82,0.31,0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(-0.68,0.31,0.35);

   //Duplicate to draw both sides (with inverted normals) when face culling is on
   glNormal3f(0,0,1);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.68,0.31,-0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(-0.82,0.31,-0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(-0.82,0.35,-0.35);

   glNormal3f(0,0,-1);
   glTexCoord2f(0.0,0.0); glVertex3f(-0.82,0.35,0.35);
   glTexCoord2f(texRepX, 0.0); glVertex3f(-0.82,0.31,0.35);
   glTexCoord2f(texRepX, texRepY); glVertex3f(-0.68,0.31,0.35);

   glEnd();

   //Undo transformations
   glPopMatrix();
}
