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
        int saldo(int kontonummer);
        void printInfo(int i);
        void printInfoFranAlla();
        void printInfoFranAllaMedNamn(string namn);
        void taBort(int kontonummer);
        void modifieraKontoinnehavare(int& kontonummer, string& namn);
        void modifieraKontotyp(int kontonummer, char typ);

        void printTillgangligaTyper();
        bool finnsKontot(int kontonummer);

    protected:
    private:
        int nastaKontonummer;
        vector<Konto> konton;
        string filnamn;

        void spara();
        void ladda();

        int antalKonton = 0;

        int hamtaKontoIndex(int kontonummer);
        bool compareStringsIgnoreCase(string str1, string str2);
        int hamtaStorstaKontonummer();
};

#endif // BANK_H
