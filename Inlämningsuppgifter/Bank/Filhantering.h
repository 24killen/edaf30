#ifndef FILHANTERING_H
#define FILHANTERING_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Konto.h"

using namespace std;

class Filhantering
{
    public:
        Filhantering();
        virtual ~Filhantering();
        void spara();
        void ladda(vector<Konto> &data);
    protected:
    private:
        ifstream input;
        ofstream output;
        string filnamn;
};

#endif // FILHANTERING_H
