#ifndef BUMPER_H
#define BUMPER_H

#include "../DataType.h"
#include "../JTKPOLBAN.h"

class Bumper
{
    public:
        Bumper(point startPoint, point endPoint, double angle, int m);
        void setStartPoint(point startPoint);
        void setEndPoint(point endPoint);
        void setPoint(point startPoint, point endPoint);
        void setAngle(double angle);
        void setM(int m);
        void draw();

    protected:

    private:
        point startPoint;
        point endPoint;
        double angle;
        int m;
};

#endif // BUMPER_H
