#include "Road.h"

Road::Road(point bottomLeftPoint, point topRightPoint)
{
    this->bottomLeftPoint = bottomLeftPoint;
    this->topRightPoint = topRightPoint;
}

void Road::setPointToX()
{
    // Set left sidewalk point
    leftSideWalkStartPoint.x = startPoint.x;
    leftSideWalkStartPoint.y = startPoint.y + 0.1;
    leftSideWalkStartPoint.z = startPoint.z + (roadSize + 1);

    // Set right sidewalk point
    rightSideWalkStartPoint.x = startPoint.x;
    rightSideWalkStartPoint.y = startPoint.y + 0.1;
    rightSideWalkStartPoint.z = startPoint.z - (roadSize + 1);

    // Set sidewalk end point
    sideWalkEndPoint.x = endPoint.x;
    sideWalkEndPoint.y = endPoint.y;
    sideWalkEndPoint.z = sideWalkSize;
}

void Road::setBottomLeftPoint(point bottomLeftPoint)
{
    this->bottomLeftPoint = bottomLeftPoint;
}

void Road::setPointToZ()
{
    // Set left sidewalk point
    leftSideWalkStartPoint.x = startPoint.x + (roadSize + 1);
    leftSideWalkStartPoint.y = startPoint.y + 0.1;
    leftSideWalkStartPoint.z = startPoint.z;

    // Set right sidewalk point
    rightSideWalkStartPoint.x = startPoint.x - (roadSize + 1);
    rightSideWalkStartPoint.y = startPoint.y + 0.1;
    rightSideWalkStartPoint.z = startPoint.z;

    // Set sidewalk end point
    sideWalkEndPoint.x = endPoint.x - 2;
    sideWalkEndPoint.y = endPoint.y;
    sideWalkEndPoint.z = sideWalkSize;
}

void Road::increaseX()
{
    startPoint.x += sideWalkSize * 2;
    rightSideWalkStartPoint.x += sideWalkSize * 2;
    leftSideWalkStartPoint.x += sideWalkSize * 2;
}

void Road::increaseZ()
{
    startPoint.z += sideWalkSize * 2;
    rightSideWalkStartPoint.z += sideWalkSize * 2;
    leftSideWalkStartPoint.z += sideWalkSize * 2;
}
