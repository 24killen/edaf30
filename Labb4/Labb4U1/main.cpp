#include <iostream>
#include "Cylinder.h"
using namespace std;

int main(){
    Cylinder c = Cylinder(10,5);
    cout << c.getHeight() << " || " << c.getRadius() << " || " << c.getVolume();
    return 0;
}
