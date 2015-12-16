#include "Cylinder.h"

Cylinder::Cylinder(double radius, double height){
    this->radius = radius;
    this->height = height;
}

Cylinder::~Cylinder(){
    //dtor
}

double getVolume(){
    return height * getArea();
}
double getHeight(){
    return height;
}
