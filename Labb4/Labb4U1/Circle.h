#ifndef CIRCLE_H
#define CIRCLE_H
#include "Cylinder.h"

class Circle{
    //riend class Cylinder;
    public:
        Circle(double r=0) : radius(r) {}
        double getArea() const;
        double getRadius() const { return radius; };
    private:
        double radius;
};
double Circle::getArea() const{
    return 3.1416*radius*radius;
}
#endif // CIRCLE_H
