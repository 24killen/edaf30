#ifndef VARDAGSRUM_H
#define VARDAGSRUM_H
#include "Rum.h"

class Vardagsrum : public Rum {
    public:
        Vardagsrum();
        Vardagsrum(int a, bool b) : Rum::Rum(a), balkong(b){}
        virtual ~Vardagsrum();
        void skriv();
    protected:
    private:
        bool balkong;
};

#endif // VARDAGSRUM_H
