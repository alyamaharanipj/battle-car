#ifndef CAMERA_H
#define CAMERA_H

#include "../DataType.h"

class Camera
{
    public:
        Camera(point startPoint, point endPoint, double angle, float stepsInc);
        void setStartPoint(point startPoint);
        point getStartPoint();
        void setEndPoint(point endPoint);
        void setPoint(point startPoint, point endPoint);
        void setAngle(double startAngle);
        double getAngle();
        void moveRight();
        void addSteps();
        void decreaseSteps();
        void addAngle();
        void decreaseAngle();
        float getStepsInc();
        float getSteps();
        void moveLeft();
        void moveBack();
        void moveFront();
        void moveCar();

    protected:

    private:
        point startPoint;
        point endPoint;
        double angle;
        float stepsInc;
        float steps;
};

#endif // CAMERA_H
