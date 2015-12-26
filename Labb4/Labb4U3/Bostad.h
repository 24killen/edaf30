#ifndef BOSTAD_H
#define BOSTAD_H
#include "Rum.h"
#include "Sovrum.h"
#include "Kok.h"
#include "Vardagsrum.h"
#include "Badrum.h"
#include <iostream>
#include <vector>

using namespace std;
class Bostad {
    public:
        Bostad(int a, bool b, bool c, int d, bool e, int f, bool g, vector<int> h, vector<int> i);
        virtual ~Bostad();
        void skriv();
    protected:
    private:
        Kok k;
        Badrum bad;
        Vardagsrum var;
        vector<Sovrum> srum;
};

#endif // BOSTAD_H
