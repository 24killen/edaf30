#include "Bank.h"
#include <iostream>

using namespace std;

Bank::Bank()
{

}

Bank::~Bank()
{

}
// Statisk variabel som används för att hålla koll på nästa ledia kontonummer.
int Bank::nastaKontonummer = 1;

// En statisk vektor som innehåller alla konton som finns i systemet.
vector<Konto> Bank::konton;

// Publik metod som hanterar inmatning och skapar
// sedan ett nytt konto samt sparar undan detta i en vektor.
void Bank::skapaKonto(){
    string kontoinnehavare;
    char kontotyp;
    bool korrekt = false;

    cout << "Skapande av nytt konto. Skriv in namn och kontotyp." << endl;

    cout << "Kontoinnehavare: ";
    cin >> kontoinnehavare;

    while(!korrekt){
        cout << endl;
        cout << "Tillgangliga typer:" << endl;
        cout << "S - Sparkonto" << endl;
        cout << "T - Transaktionskonto" << endl << endl;

        cout << "Kontotyp: ";
        cin >> kontotyp;
        kontotyp = toupper(kontotyp);

        if(kontotyp == 'S' || kontotyp == 'T' ){
            korrekt = true;
        }else{
            cout << "Kontotyp " << kontotyp << " finns inte. Forsok igen." << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }
    skapaKonto(kontoinnehavare, kontotyp);
}

// Privat metod som används av den publika metoden med samma namn.
// Metoden skapar ett nytt konto med den korrekta inmatningen och
// sparar detta i den statiska vektorn "konton".
void Bank::skapaKonto(string kontoinnehavare, char kontotyp){
    Konto k(kontoinnehavare, nastaKontonummer++, kontotyp);
    konton.push_back(k);
    antalKonton++;
}

// Publik metod som används för att lägga till ett belopp på ett visst konto.
// Metoden använder två privata hjälpmetoder för att hantera inmatningen av
// kontonummer och belopp. (kontonummerInput() och beloppInput())
void Bank::sattIn(){
    int kontonummer = kontonummerInput();
    if(kontonummer != 0){
        int belopp = beloppInput();
        while(belopp<0){
            cout << "Du kan inte satta in mindre an 0 kr pa ditt konto. Forsok igen." << endl;
            belopp = beloppInput();
        }
        sattIn(kontonummer, belopp);
    }
}

// Privat metod som sätter in det korrekta belopped till det korrekta kontot.
void Bank::sattIn(int kontonummer, int belopp){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).sattIn(belopp);
}

void Bank::printInfoFranAlla(){
    cout << "Information fran alla konton: " << endl;
    cout << "__________________________________________" << endl;
    for(int i = 0; i < antalKonton; i++){
        cout << "Kontoinnehavare: " << konton.at(i).getKontoinnehavare() << endl;
        cout << "Kontonummer: " << konton.at(i).getKontonummer() << endl;
        cout << "Kontotyp: " << konton.at(i).getKontotyp() << endl;
        cout << "Summa: " << konton.at(i).getSumma() << endl;
        cout << "__________________________________________" << endl;
    }
}

// Hanterar inmatningen av kontonummer och
// kontrollerar att kontonumret finns.
// Returnerar det korrekt inmatade kontonumret
// eller 0 om användaren väljer att avbryta.
int Bank::kontonummerInput(){
    int kontonummer;
    bool korrekt = false;
    string dummy;
    cout << "Skriv in ditt kontonummer, avbryt med 0" << endl;
    while(!korrekt && kontonummer != 0){
        cout << "Kontonummer: ";
        if(cin >> kontonummer){
            if(finnsKontot(kontonummer)){
                korrekt = true;
            }else{
                cout << "Kontonummer " << kontonummer << " finns inte. Forsok igen." << endl;
            }
        }else{
            cin.clear();
            cin >> dummy;
            cout << "Felaktig inmatning for kontonummer, forsok igen." << endl;
            kontonummer = -1;
        }
    }
    return kontonummer;
}

// Hanterar inmatningen av belopp-värdet.
// Returnerar belopp-värdet.
int Bank::beloppInput(){
    int belopp;
    bool korrekt = false;
    string dummy;
    while(!korrekt){
        cout << "Belopp: ";
        if(cin >> belopp){
            korrekt = true;
        }else{
            cin.clear();
            cin >> dummy;
            cout << "Felaktig inmatning for belopp, forsok igen." << endl;
            belopp = -1;
        }
    }
    return belopp;
}

int Bank::hamtaKontoIndex(int kontonummer){
    for(int i = 0; i < antalKonton; i++){
        if(kontonummer == konton.at(i).getKontonummer()){
            return i;
        }
    }
    return -1;
}

// Kontrollerar om ett inmatat kontonummer finns.
// Returnerar true om det finns, och false om det inte finns.
bool Bank::finnsKontot(int kontonummer){
    if(hamtaKontoIndex(kontonummer) != -1){
        return true;
    }
    return false;
}
