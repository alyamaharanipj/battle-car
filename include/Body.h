#ifndef BODY_H
#define BODY_H

#include <../DataType.h>

class Body
{
    public:
        Body(point startPoint, point endPoint, double angle, int w);
        void setStartPoint(point startPoint);
        void setEndPoint(point endPoint);
        void setPoint(point startPoint, point endPoint);
        void setAngle(double angle);
        void setW(int w);
        void draw();

    protected:

    private:
        point startPoint;
        point endPoint;
        double angle;
        int w;
        int s;
};

#endif // BODY_H
