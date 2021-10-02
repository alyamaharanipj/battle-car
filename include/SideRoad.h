#ifndef SIDEROAD_H
#define SIDEROAD_H

#include "Road.h"
#include "Cube.h"

class SideRoad : public Road
{
    public:
        SideRoad(point startPoint, point endPoint);
        void draw();


    protected:

    private:
        void drawFront();
        void drawBack();
        void drawLeft();
        void drawRight();

        void setFrontPoint();
        void setBackPoint();
        void setLeftPoint();
        void setRightPoint();

       float landSize = totalRoadSize * 5 + 1;
       float leftPoint = (landSize * -2.5) - totalRoadSize;
       float rightPoint = (landSize * 2.5) + totalRoadSize;
};

#endif // SIDEROAD_H
