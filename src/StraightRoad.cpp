#include "StraightRoad.h"

StraightRoad::StraightRoad(point startPoint, point endPoint) : Road(startPoint, endPoint){}

void StraightRoad::setPoint()
{
    startPoint = bottomLeftPoint;
    endPoint = topRightPoint;
}

void StraightRoad::drawVertically()
{
     setPoint();
     startPoint.z += 0.1;
    endPoint.x = roadSize;
    setPointToZ();
    for(int i = 0; i < 14; i++){
        Cube road(startPoint, endPoint, 8, 0, texScale);
        Cube rightSideWalk(rightSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        Cube leftSideWalk(leftSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        if(i % 14 > 2)
        {
            road.draw();
        }
        if (i % 14 > 3)
        {
            leftSideWalk.draw();
            rightSideWalk.draw();
        }

        increaseZ();
    }
}

void StraightRoad::drawHorizontally()
{
    setPoint();
    setPointToX();
    for(int i = 0; i < 13; i++){
        Cube road(startPoint, endPoint, 8, 0, texScale);
        Cube rightSideWalk(rightSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        Cube leftSideWalk(leftSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);

        rightSideWalk.draw();
        road.draw();

        leftSideWalk.draw();

        increaseX();
    }
}
