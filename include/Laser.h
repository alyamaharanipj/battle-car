#ifndef LASER_H
#define LASER_H

#include "../DataType.h"

class Laser
{
    public:
        Laser(float angle, float stepsInc);
        Laser(point startPoint, point endPoint, float angle, float stepsInc);
        void draw();
        void setStartPoint(point startPoint);
        void setEndPoint(point endPoint);
        void setAngle(float angle);
        point getStartPoint();
        point getEndPoint();
        float getSteps();
        void addSteps();
        void moveLeft();
        void resetStep();

    protected:

    private:
        point startPoint;
        point endPoint;
        float angle;
        float stepsInc;
        float steps;
};

#endif // LASER_H
