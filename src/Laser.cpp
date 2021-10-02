#include "Laser.h"
#include <GL/glut.h>
#include <cstdio>

Laser::Laser(point startPoint, point endPoint, float angle, float stepsInc){
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->angle = angle;
    this->stepsInc = stepsInc;
    this->steps = 0;
}

Laser::Laser(float angle, float stepsInc){
    this->angle = angle;
    this->stepsInc = stepsInc;
    this->steps = 0;
}

void Laser::setAngle(float angle)
{
    this->angle = angle;
}

void Laser::setStartPoint(point startPoint)
{
    this->startPoint = startPoint;
}

void Laser::setEndPoint(point endPoint)
{
    this->endPoint = endPoint;
}
float Laser::getSteps()
{
    return steps;
}


void Laser::moveLeft()
{
    this->startPoint.x -= stepsInc;
}


void Laser::addSteps()
{
    this->steps += stepsInc;
}


point Laser::getStartPoint()
{
    return startPoint;
}

point Laser::getEndPoint()
{
    return endPoint;
}

void Laser::resetStep()
{
    this->steps = 0;
}

void Laser::draw()
{
    glLineWidth(3);
    glColor3f(1, 1, 1);
	glBegin(GL_LINES);
        glVertex3f(endPoint.x,endPoint.y,endPoint.z);
        glVertex3f(startPoint.x,startPoint.y,startPoint.z);
	glEnd();
}


