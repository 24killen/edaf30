#ifndef RUM_H
#define RUM_H
#include "Rum.h"
#include <iostream>

class Rum{
    public:
        Rum();
        Rum(int y) : yta(y){}
        virtual ~Rum() {}
        virtual void skriv() const {std::cout << "Yta: " << yta;}
    protected:
    private:
        int yta;
};

#endif // RUM_H
