#include "Konto.h"
#include <random>
#include <vector>

using namespace std;

Konto::Konto(string namn, int nbr, char typ)
{
    kontoinnehavare = namn;
    kontonummer = nbr;
    kontotyp = typ;
    saldo = 0;
}

Konto::~Konto()
{

}

void Konto::setKontoinnehavare(string namn){
    kontoinnehavare = namn;
}

string const Konto::getKontoinnehavare(){
    return kontoinnehavare;
}

void Konto::setKontonummer(int nbr){
    kontonummer = nbr;
}

int const Konto::getKontonummer(){
    return kontonummer;
}

void Konto::setKontotyp(char typ){
    kontotyp = typ;
}

char const Konto::getKontotyp(){
    return kontotyp;
}

void Konto::sattIn(int sattIn){
    saldo += sattIn;
}

void Konto::taUt(int taUt){
    saldo -= taUt;
}

int const Konto::getSaldo(){
    return saldo;
}
