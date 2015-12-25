#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include "Pet.h"

using namespace std;
class Bird : public Pet{
    public:
        Bird(string s) : Pet(s){}
        virtual ~Bird();
        string speak() { return sound;}
    protected:
    private:
};

#endif // BIRD_H
