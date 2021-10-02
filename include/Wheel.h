#ifndef WHEEL_H
#define WHEEL_H

#include "../DataType.h"
#include "../JTKPOLBAN.h"

class Wheel
{
    public:
        Wheel(point startPoint, point endPoint, double angle, int d, int s);
        void setStartPoint(point startPoint);
        void setEndPoint(point endPoint);
        void setPoint(point startPoint, point endPoint);
        void setAngle(double angle);
        void setD(int d);
        void setS(int s);
        void draw();

    protected:

    private:
        point startPoint;
        point endPoint;
        double angle;
        int d;
        int s;
};

#endif // WHEEL_H
