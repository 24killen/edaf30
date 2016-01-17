#ifndef KONTO_H
#define KONTO_H
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Konto
{
    public:
        Konto(string namn, int nbr, char typ);
        virtual ~Konto();
        void setKontoinnehavare(string namn);
        string const getKontoinnehavare();
        void setKontonummer(int nbr);
        int const getKontonummer();
        void setKontotyp(char typ);
        char const getKontotyp();
        void sattIn(int belopp);
        void taUt(int belopp);
        int const getSaldo();
    protected:
    private:
        string kontoinnehavare;
        int kontonummer;
        char kontotyp;
        int saldo;
};

#endif // KONTO_H
