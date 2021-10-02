#ifndef CAR_H
#define CAR_H

#include "../DataType.h"
#include "Bumper.h"
#include "Wheel.h"
#include "Body.h"
#include "Laser.h"

class Car
{
    public:
        Car(point startPoint, point endPoint, double angle, color carColor, float stepsInc);
        void setStartPoint(point startPoint);
        point getStartPoint();
        void setEndPoint(point endPoint);
        void setPoint(point startPoint, point endPoint);
        void setAngle(double startAngle);
        void setColor(color carColor);
        void draw();
        void drawPanels();
        void drawTrunk();
        void drawWindshield();
        void drawRearWindow();
        void drawSpoiler();
        double getAngle();
        void moveRight();
        void addSteps();
        void resetStep();
        void decreaseSteps();
        void addAngle();
        void decreaseAngle();
        float getStepsInc();
        float getSteps();
        void moveLeft();
        void moveBack();
        void moveFront();
        void moveCar();
        void setCollide(bool collide);
        bool isCollided();
        void decreaseStepsInc();
        void increaseStepsInc();
        void drawLaser();
        void shoot();
        void getLaser();


    protected:

        point startPoint;
        point endPoint;
        bool collide = false;
        double angle;
        float stepsInc;
        float steps;
        color carColor;
        void drawWheel();
        void drawBody();
        void drawBumper();
        float laserSteps;
        bool isShoot = false;

    private:

};

#endif // CAR_H
