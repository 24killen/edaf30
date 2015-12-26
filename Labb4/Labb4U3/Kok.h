#ifndef KOK_H
#define KOK_H
#include "Rum.h"
#include <iostream>


class Kok : public Rum {
    public:
        Kok();
        Kok(int a, bool b, bool c) : Rum::Rum(a), diskmaskin(b), frys(c){}
        virtual~Kok();
        void skriv();
    protected:
    private:
        bool diskmaskin, frys;
};

#endif // KOK_H
