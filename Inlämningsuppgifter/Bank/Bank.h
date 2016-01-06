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
        void skapaKonto();
        void sattIn();
        void taUt();
        void saldo();
        void printInfoFranAlla();
        void printInfoFranAllaMedNamn();
        void taBort();
        void modifiera();

    protected:
    private:
        int nastaKontonummer;
        vector<Konto> konton;
        string filnamn;
        ifstream input;
        ofstream output;

        void spara();
        void ladda();

        int antalKonton = 0;
        int beloppInput();
        void skapaKonto(string kontoinnehavare, char kontotyp);
        void sattIn(int kontonummer, int belopp);
        void taUt(int kontonummer, int belopp);
        void saldo(int kontonummer);
        void printInfoFranAllaMedNamn(string namn);
        void taBort(int kontonummer);
        void modifieraKontoinnehavare(int kontonummer);
        void modifieraKontotyp(int kontonummer);


        void printInfo(int i);
        int kontonummerInput();
        int hamtaKontoIndex(int kontonummer);
        bool finnsKontot(int kontonummer);
        bool compareStringsIgnoreCase(string str1, string str2);
        void printTillgangligaTyper();
        int hamtaStorstaKontonummer();
};

#endif // BANK_H
