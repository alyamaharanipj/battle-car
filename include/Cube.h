#ifndef CUBE_H
#define CUBE_H

#include "BasicDisplay.h"

class Cube
{
    public:
        Cube();
        Cube(point startPoint, point endPoint, GLint texture, float _angle, float texScale);

        void draw();
        void setStartPoint(point startPoint);
        void setEndPoint(point endPoint);
        void setPoint(point startPoint, point endPoint);

    protected:


    private:
        GLint texture;
        tile objectTile;
        point startPoint;
        point endPoint;
        float _angle;
        point dStartPoint;
        point dEndPoint;
        float texScale;
        void setCoordinate();
        void drawFront();
        void drawBack();
        void drawLeft();
        void drawRight();
        void drawTop();
        void drawBottom();
};

#endif // CUBE_H
