#ifndef BADRUM_H
#define BADRUM_H
#include "Rum.h"
#include <iostream>

class Badrum : public Rum {
    public:
        Badrum();
        Badrum(int a, bool b) : Rum::Rum(a), dusch(b){}
        virtual ~Badrum();
        void skriv();
    protected:
    private:
        bool dusch;
};

#endif // BADRUM_H
