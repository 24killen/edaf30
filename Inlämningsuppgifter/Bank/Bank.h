#ifndef BANK_H
#define BANK_H
#include <vector>
#include "Konto.h"

using namespace std;

class Bank
{

    public:
        Bank();
        virtual ~Bank();
        static int nastaKontonummer;
        static vector<Konto> konton;
        void skapaKonto();
        void sattIn();

        void printInfoFranAlla();
    protected:
    private:
        int antalKonton = 0;
        int beloppInput();
        void skapaKonto(string kontoinnehavare, char kontotyp);
        void sattIn(int kontonummer, int belopp);

        int kontonummerInput();
        int hamtaKontoIndex(int kontonummer);
        bool finnsKontot(int kontonummer);
};

#endif // BANK_H
