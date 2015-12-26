#ifndef SOVRUM_H
#define SOVRUM_H
#include "Rum.h"
#include <iostream>


class Sovrum : public Rum {
    public:
        Sovrum();
        Sovrum(int a, int b) : Rum::Rum(a), garderober(b){}
        virtual ~Sovrum();
        void skriv();
    protected:
    private:
        int garderober;
};

#endif // SOVRUM_H
