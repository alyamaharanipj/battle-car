#ifndef STRAIGHTROAD_H
#define STRAIGHTROAD_H

#include "../DataType.h"
#include "Cube.h"
#include "Road.h"

class StraightRoad : public Road
{
    public:
        StraightRoad(point startPoint, point endPoint);
        void draw();
        void drawHorizontally();
        void drawVertically();

    protected:

    private:
        void setPoint();
        void setLeftPoint();

};

#endif // STRAIGHTROAD_H
