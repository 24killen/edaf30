#ifndef CAT_H
#define CAT_H
#include <iostream>
#include "Pet.h"
#include <string>
using namespace std;

class Cat : public Pet{
    public:
        Cat(string s) : Pet::Pet(s){}
        virtual ~Cat();
        string speak() {return sound;}
    protected:
    private:
};

#endif // CAT_H
