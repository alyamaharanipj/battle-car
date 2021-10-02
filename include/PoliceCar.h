#ifndef POLICECAR_H
#define POLICECAR_H

#include <Car.h>

#include "../DataType.h"
#include <Car.h>

class PoliceCar : public Car
{
    public:
        PoliceCar(point startPoint, point endPoint, double angle, color carColor, float stepsInc);
        drawPolice();

    protected:

    private:
};

#endif // POLICECAR_H
