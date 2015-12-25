#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "Pet.h"

using namespace std;
class Dog : public Pet{
    public:
        Dog(string s) : Pet(s){}
        virtual ~Dog();
        string speak(){return sound;}
    protected:
    private:
};

#endif // DOG_H
