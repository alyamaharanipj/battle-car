#ifndef BASICDISPLAY_H
#define BASICDISPLAY_H

#include "../DataType.h"
class BasicDisplay
{
    public:
        BasicDisplay();
        BasicDisplay(point startPoint, point endPoint, tile objectTile, GLint texture, float _angle);
        void displayFront();
        void displaySide();
        void displayBase();

    protected:
        GLint texture;
        tile objectTile;
        point startPoint;
        point endPoint;
        float _angle;

    private:

};

#endif // BASICDISPLAY_H
