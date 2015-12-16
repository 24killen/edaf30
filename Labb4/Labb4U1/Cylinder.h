#ifndef CYLINDER_H
#define CYLINDER_H
#include "Circle.h"


class Cylinder : public Circle {

    public:
        Cylinder(double radius, double height);
        virtual ~Cylinder();
        double getVolume();
        double getHeight();
    protected:
    private:
        double height;
};

#endif // CYLINDER_H
