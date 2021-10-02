#include "Camera.h"

Camera::Camera(point startPoint, point endPoint, double angle, float stepsInc)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->angle = angle;
    this->steps = 0;
    this->stepsInc = stepsInc;
}

void Camera::setStartPoint(point startPoint)
{
    this->startPoint = startPoint;
}

point Camera::getStartPoint()
{
    return startPoint;
}

void Camera::setEndPoint(point endPoint)
{
    this->endPoint = endPoint;
}

void Camera::setPoint(point startPoint, point endPoint)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

void Camera::setAngle(double startAngle)
{
    this->angle = angle;
}

void Camera::addAngle()
{
    this->angle += 1;
}

void Camera::decreaseAngle()
{
    this->angle -= 1;
}

void Camera::moveRight()
{
    this->startPoint.x += stepsInc;
}

void Camera::moveLeft()
{
    this->startPoint.x -= stepsInc;
}

void Camera::moveBack()
{
    this->startPoint.z -= stepsInc;
}

void Camera::moveFront()
{
    this->startPoint.z += stepsInc;
}

double Camera::getAngle()
{
    return angle;
}

float Camera::getStepsInc()
{
    return stepsInc;
}

float Camera::getSteps()
{
    return steps;
}

void Camera::addSteps()
{
    this->steps += stepsInc;
}

void Camera::decreaseSteps()
{
    this->steps -= stepsInc;
}

