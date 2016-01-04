#ifndef KONTON_H
#define KONTON_H
#include <iostream>
#include <vector>
#include "Konto.h"

using std::vector;

class Konton
{
    public:
        Konton();
        virtual ~Konton();
        vector<Konto> getKonton();
    protected:
    private:
        static vector<Konto> konton;
};

#endif // KONTON_H
