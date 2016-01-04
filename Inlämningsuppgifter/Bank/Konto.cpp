#include "Konto.h"
#include <random>
#include <vector>

using namespace std;

Konto::Konto(string namn, int nbr, char typ)
{
    kontoinnehavare = namn;
    kontonummer = nbr;
    kontotyp = typ;
    summa = 0;
}

Konto::~Konto()
{

}

void Konto::setKontoinnehavare(string namn){
    kontoinnehavare = namn;
}

string Konto::getKontoinnehavare(){
    return kontoinnehavare;
}

void Konto::setKontonummer(int nbr){
    kontonummer = nbr;
}

int Konto::getKontonummer(){
    return kontonummer;
}

void Konto::setKontotyp(char typ){
    kontotyp = typ;
}

char Konto::getKontotyp(){
    return kontotyp;
}

void Konto::sattIn(int sattIn){
    summa += sattIn;
}

void Konto::taUt(int taUt){
    summa -= taUt;
}

int Konto::getSumma(){
    return summa;
}
