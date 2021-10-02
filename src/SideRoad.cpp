#include "SideRoad.h"

SideRoad::SideRoad(point bottomLeftPoint, point topRightPoint) : Road(bottomLeftPoint, topRightPoint){}

void SideRoad::draw()
{
    drawFront();
    drawLeft();
    drawRight();
    drawBack();
}

void SideRoad::setFrontPoint()
{
    startPoint.x = bottomLeftPoint.x + 2;
    startPoint.y = bottomLeftPoint.y;
    startPoint.z = bottomLeftPoint.z ;

    endPoint.x = sideWalkSize;
    endPoint.y = topRightPoint.y;
    endPoint.z = roadSize;
}

void SideRoad::setBackPoint()
{
    startPoint.x = bottomLeftPoint.x + 2;
    startPoint.y = bottomLeftPoint.y;
    startPoint.z = rightPoint - totalRoadSize;

    endPoint.x = sideWalkSize;
    endPoint.y = topRightPoint.y;
    endPoint.z = roadSize;
}

void SideRoad::setLeftPoint()
{
    startPoint.x = topRightPoint.x;
    startPoint.y = bottomLeftPoint.y;
    startPoint.z = topRightPoint.z;

    endPoint.x = roadSize;
    endPoint.y = topRightPoint.y;
    endPoint.z = sideWalkSize;
}

void SideRoad::setRightPoint()
{
    startPoint.x = leftPoint + sideWalkSize * 6;
    startPoint.y = bottomLeftPoint.y;
    startPoint.z = topRightPoint.z;

    endPoint.x = roadSize;
    endPoint.y = topRightPoint.y;
    endPoint.z = sideWalkSize;
}

void SideRoad::drawFront()
{
    setFrontPoint();
    setPointToX();
    for(int i = 0; i < rightPoint - sideWalkSize; i++){
        Cube road(startPoint, endPoint, 8, 0, texScale);
        Cube rightSideWalk(rightSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        Cube leftSideWalk(leftSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        rightSideWalk.draw();
        if ( i < rightPoint )
        {
            road.draw();
        }
        if (i % 16 > 3)
        {
            leftSideWalk.draw();
        }
        increaseX();
    }
}

void SideRoad::drawBack()
{
    setBackPoint();
    setPointToX();
    for(int i = 0; i < rightPoint - sideWalkSize; i++){
        Cube road(startPoint, endPoint, 8, 0, texScale);
        Cube rightSideWalk(rightSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        Cube leftSideWalk(leftSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        leftSideWalk.draw();
        if ( i < rightPoint)
        {
            road.draw();
        }
        if(i % 16 > 3){
            rightSideWalk.draw();
        }
        increaseX();
    }
}

void SideRoad::drawLeft()
{
    setLeftPoint();
    setPointToZ();

    for(int i = 0; i < rightPoint; i++){
        Cube road(startPoint, endPoint, 8, 0, texScale);
        Cube rightSideWalk(rightSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        Cube leftSideWalk(leftSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);

        leftSideWalk.draw();
        if(i < rightPoint - totalRoadSize + sideWalkSize && i > totalRoadSize - sideWalkSize * 2){
            road.draw();
        }
        if((i % 13 > 3)){
            rightSideWalk.draw();
        }
        increaseZ();
    }
}

void SideRoad::drawRight()
{
    setRightPoint();
    setPointToZ();

    for(int i = 0; i < rightPoint; i++){
        Cube road(startPoint, endPoint, 8, 0, texScale);
        Cube rightSideWalk(rightSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);
        Cube leftSideWalk(leftSideWalkStartPoint, sideWalkEndPoint, 0, 0, texScale);

        rightSideWalk.draw();
        if(i < rightPoint - totalRoadSize + sideWalkSize && i > totalRoadSize - sideWalkSize * 2){
            road.draw();
        }
        if(i % 13 > 3){
            leftSideWalk.draw();
        }
        increaseZ();
    }
}
