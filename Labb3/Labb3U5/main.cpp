#include <iostream>
#include "Kvadrat.h"

using namespace std;

int main(){

    Kvadrat kv1 = 2;
    Kvadrat kv2 = 2;
    int a,b;
    cout << "Creates square 1 and 2 with side 2." << endl << endl;

    ++kv1;
    --kv2;
    cout << "The side on square 1 ++, the side on square 2 --" << endl;
    cout << "The area is: " << kv1.area() << "||" << kv2.area() << endl;
    kv1-=2;
    kv2+=2;
    cout << endl << "The side on square 1 -= 2, the side on square 2 += " << endl;
    cout << "The area is: " << kv1.area() << "||" << kv2.area() << endl;
    a = kv1<kv2;
    b = kv2>kv1;
    cout << endl << "Square 1 < square 2 (1 = square 1 is bigger, 0 = equal, -1 = square 2 is bigger)" << endl;
    cout << "Square 2 > square 1 (1 = square 1 is bigger, 0 = equal, -1 = square 2 is bigger)" << endl;
    cout << a << "||" << b << endl;

    cout << endl << "Square 1 == square 2 (1 = square 1 is bigger, 0 = equal, -1 = square 2 is bigger)" << endl;
    cout << (kv1==kv2) << endl << endl;

    //cout << kv.area();
    return 0;
}
