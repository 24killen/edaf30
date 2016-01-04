#ifndef KONTO_H
#define KONTO_H
#include <iostream>

class Konto
{
    public:
        Konto();
        virtual ~Konto();
    protected:
    private:
        std::string kontoinnehavare;
        int kontonummer;
};

#endif // KONTO_H
