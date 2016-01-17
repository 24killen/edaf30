#ifndef BANK_H
#define BANK_H
#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <stdlib.h>
#include "Konto.h"
#include <fstream>

using namespace std;

class Bank
{
    public:
        Bank(string fil);
        virtual ~Bank();
        int skapaKonto(string kontoinnehavare, char kontotyp);
        void sattIn(int kontonummer, int belopp);
        void taUt(int kontonummer, int belopp);
        int const saldo(int kontonummer);
        void const printInfo(int i);
        void const printInfoFranAlla();
        void const printInfoFranAllaMedNamn(string namn);
        void taBort(int kontonummer);
        void modifieraKontoinnehavare(int& kontonummer, string& namn);
        void modifieraKontotyp(int kontonummer, char typ);

        void const printTillgangligaTyper();
        bool const finnsKontot(int kontonummer);

    protected:
    private:
        int nastaKontonummer;
        vector<Konto> konton;
        string filnamn;

        void spara();
        void ladda();

        int antalKonton = 0;

        int const hamtaKontoIndex(int kontonummer);
        bool const compareStringsIgnoreCase(string str1, string str2);
        int const hamtaStorstaKontonummer();
};

#endif // BANK_H
