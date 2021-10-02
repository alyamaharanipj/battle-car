#ifndef ROAD_H
#define ROAD_H

#include "../DataType.h"

class Road
{
    public:
        Road(point startPoint, point endPoint);
        void setBottomLeftPoint(point bottomLeftPoint);

    protected:
        void setPointToX();
        void setPointToZ();
        void setPointToZ2();
        void increaseX();
        void increaseZ();
        point startPoint;
        point endPoint;
        point bottomLeftPoint;
        point topRightPoint;
        point leftSideWalkStartPoint;
        point rightSideWalkStartPoint;
        point sideWalkEndPoint;
        float roadSize = 3;
        float sideWalkSize = 1;
        float totalRoadSize = roadSize + sideWalkSize + 1;
        tile objectTile{1,1};
        float texScale = 0.5;

    private:
};

#endif // ROAD_H
