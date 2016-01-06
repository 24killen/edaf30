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
        string getKontoinnehavare();
        void setKontonummer(int nbr);
        int getKontonummer();
        void setKontotyp(char typ);
        char getKontotyp();
        void sattIn(int belopp);
        void taUt(int belopp);
        int getSaldo();
    protected:
    private:
        string kontoinnehavare;
        int kontonummer;
        char kontotyp;
        int saldo;
};

#endif // KONTO_H
