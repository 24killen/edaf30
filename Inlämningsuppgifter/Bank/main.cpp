#include <iostream>
#include <random>
#include <ctime>
#include "Konto.h"
#include "Bank.h"
#include "Test.h"

using namespace std;

void printMenu();

void skapaKonto(Bank& b);
void sattIn(Bank& b);
void taUt(Bank& b);
void saldo(Bank& b);
void printInfoFranAllaMedNamn(Bank& b);
void taBort(Bank& b);
void modifiera(Bank& b);
void modifieraKontoinnehavare(int kontonummer, Bank& b);
void modifieraKontotyp(int kontonummer, Bank& b);

int kontonummerInput(Bank& b);
int beloppInput();


int main()
{
    bool test = true;

    if(test){
        Test t;
        t.startaTest();
        return 0;
    }

    string filnamn = "Banksystem.txt";
    Bank b(filnamn);

    int val = -1;
    string dummy;
    while(val!=0){
        printMenu();
        if(cin >> val){ // If the input is an int
            switch(val){
                case 0: // Avsluta programmet
                    break;
                case 1: // Skapa konto
                    skapaKonto(b);
                    break;
                case 2: // Insattning av belopp till konto
                    sattIn(b);
                    break;
                case 3: // Uttag av belopp fran konto
                    taUt(b);
                    break;
                case 4: // Fraga om saldo for konto
                    saldo(b);
                    break;
                case 5: // Lista information for alla konton
                    b.printInfoFranAlla();
                    break;
                case 6: // Lista information for alla konton for en viss kontoinnehavare
                    printInfoFranAllaMedNamn(b);
                    break;
                case 7: // Avsluta (ta bort) ett existerande konto
                    taBort(b);
                    break;
                case 8: // Modifiera ett existerande konto
                    modifiera(b);
                    break;
                default:// Övriga värden
                    cout << "Menyval " << val << " finns inte i menyn, forsok igen." << endl;
                    break;
            }
        }
        else{ // Vid annan inmatning än en int.
            cin.clear();    // Nollställ cin
            cin >> dummy;   // Lägg in en dummy
            val = -1;       // Sätter menyvalet till initieringsvärdet
            cout << "Inkorrekt inmatning, forsok igen!" << endl;    // Skriver ut felmeddelande
        }
    }

    return 0;
}

// Prints the menu
void printMenu(){
    cout << "---------------MENY---------------" << endl;
    cout << "1. Skapa konto" << endl;
    cout << "2. Insattning av belopp till konto" << endl;
    cout << "3. Uttag av belopp fran konto" << endl;
    cout << "4. Fraga om saldo for konto" << endl;
    cout << "5. Lista information for alla konton" << endl;
    cout << "6. Lista information for alla konton for en viss kontoinnehavare" << endl;
    cout << "7. Avsluta (ta bort) ett existerande konto" << endl;
    cout << "8. Modifiera ett existerande konto" << endl;
    cout << "0. Avsluta programmet" << endl;
}

// Publik metod som hanterar inmatning och skapar
// sedan ett nytt konto samt sparar undan detta i en vektor.
void skapaKonto(Bank& b){
    string kontoinnehavare;
    char kontotyp;
    bool korrekt = false;

    cout << "Skapande av nytt konto. Skriv in namn och kontotyp." << endl;

    cout << "Kontoinnehavare: ";
    cin.ignore();
    getline(cin,kontoinnehavare);

    while(!korrekt){
        b.printTillgangligaTyper();

        cout << "Kontotyp: ";
        cin >> kontotyp;
        kontotyp = toupper(kontotyp);

        if(kontotyp == 'S' || kontotyp == 'T' ){
            korrekt = true;
            cin.sync();
        }else{
            cout << "Kontotyp " << kontotyp << " finns inte. Forsok igen." << endl;
            cout << "----------------------------------------------------" << endl;
            cin.sync();
        }
    }
    b.skapaKonto(kontoinnehavare, kontotyp);
}

// Publik metod som används för att lägga till ett belopp på ett visst konto.
// Metoden använder två privata hjälpmetoder för att hantera inmatningen av
// kontonummer och belopp. (kontonummerInput() och beloppInput())
void sattIn(Bank& b){
    int kontonummer = kontonummerInput(b);
    if(kontonummer != 0){
        int belopp = beloppInput();
        while(belopp<0){
            cout << "Du kan inte satta in mindre an 0 kr pa ditt konto. Forsok igen." << endl;
            belopp = beloppInput();
        }
        b.sattIn(kontonummer, belopp);
    }
}

// Hanterar inmatningen för att ta ut en specifik
// summa pengar från ett specifikt konto.
void taUt(Bank& b){
    int kontonummer = kontonummerInput(b);
    if(kontonummer != 0){
        int belopp = beloppInput();
        while(belopp<0){
            cout << "Du kan inte ta ut mindre an 0 kr pa ditt konto. Forsok igen." << endl;
            belopp = beloppInput();
        }
        b.taUt(kontonummer, belopp);
    }
}

// Hanterar inmatning för att hämta saldot för ett specifikt konto.
void saldo(Bank& b){
    int kontonummer = kontonummerInput(b);
    int saldo = 0;
    if(kontonummer != 0){
       saldo = b.saldo(kontonummer);
        cout << "Saldot for kontonummer " << kontonummer << " ar: " << saldo << endl;
    }
}


// Hanterar inmatningen för att skriva ut vilka konton som ägs av samma kontoinnehavare.
void printInfoFranAllaMedNamn(Bank& b){
    string namn;
    cout << "Namn: ";
    cin.ignore();
    getline(cin,namn);
    b.printInfoFranAllaMedNamn(namn);
}

// Hanterar inmatning och bekräftelse för att ta bort ett konto.
void taBort(Bank& b){
    int kontonummer = kontonummerInput(b);
    char bekrafta;
    char dummy;
    bool korrekt = false;
    while(!korrekt && kontonummer != 0){
        cout << "Ar du saker pa att du vill ta bort detta konto? (Y/n)";
        if(cin >> bekrafta){
            if(toupper(bekrafta) == 'Y' || toupper(bekrafta) == 'N'){
                korrekt = true;
                cin.sync();
                if(toupper(bekrafta) == 'Y'){
                    b.taBort(kontonummer);
                }else{
                    cout << "Avstangning avbruten, ingenting ar andrat." << endl;
                }
            }else{
                cout << "Felaktig inmatning for bekraftande. Forsok igen" << endl;
                cin.sync();
            }
        }else{
            cin.clear();
            cin >> dummy;
        }
    }
}


// Visar en meny och hanterar inmatning för denna.
// Startar olika funktioner beroende på menyval.
void modifiera(Bank& b){
    int kontonummer = kontonummerInput(b);
    bool korrekt = false;
    int val;
    string dummy;
    while(!korrekt && kontonummer != 0){
        cout << "----- Modifiera konto -----" << endl;
        cout << "1. Kontoinnehavare" << endl;
        cout << "2. Kontotyp" << endl;
        cout << "0. Aterga till huvudmenyn" << endl;
        if(cin >> val){
            switch(val){
            case 0:
                korrekt = true;
                cout << "Atergar till huvudmenyn." << endl;
                break;
            case 1:
                modifieraKontoinnehavare(kontonummer,b);
                break;
            case 2:
                modifieraKontotyp(kontonummer,b);
                break;
            default:
                cout << "Fel, det fanns inget alternativ som matchar ditt val. (" << val << ")"  << endl;
                cout << "Atergar till huvudmenyn." << endl;
                break;
            }
        }else{
            cin.clear();
            cin >> dummy;
            val = -1;
            cout << "Felaktig inmatning vid val av modifiering. Forsok igen" << endl;
        }
    }
}

void modifieraKontoinnehavare(int kontonummer, Bank& b){
    string namn;
    if(kontonummer != 0){
        cout << "Nytt namn: ";
        cin.ignore();
        getline(cin,namn);
        b.modifieraKontoinnehavare(kontonummer,namn);
    }
}

// En metod för att kontrollera och hantera ändringar av kontotypen för ett specifikt konto.
void modifieraKontotyp(int kontonummer, Bank& b){
    bool korrekt = false;
    char typ, dummy;
    while(!korrekt && kontonummer != 0){
        b.printTillgangligaTyper();
        cout << "Kontotyp: ";
        if(cin >> typ){
            typ = toupper(typ);
            if(typ == 'S' || typ == 'T' ){
                korrekt = true;
                b.modifieraKontotyp(kontonummer,typ);
                cin.sync();
            }else{
                cout << "Kontotyp " << typ << " finns inte. Forsok igen." << endl;
                cout << "----------------------------------------------------" << endl;
                cin.sync();
            }
        }else{
            cin.clear();
            cin >> dummy;
            typ = ' ';
            cout << "Felaktig inmatning for andring av kontotyp, forsok igen." << endl;
        }
    }
}


// Hanterar inmatningen av kontonummer och
// kontrollerar att kontonumret finns.
// Returnerar det korrekt inmatade kontonumret
// eller 0 om användaren väljer att avbryta.
int kontonummerInput(Bank& b){
    int kontonummer;
    bool korrekt = false;
    string dummy;
    cout << "Skriv in ditt kontonummer, avbryt med 0" << endl;
    while(!korrekt){
        cout << "Kontonummer: ";
        if(cin >> kontonummer){
            if(kontonummer == 0){
                return kontonummer;
            }
            if(b.finnsKontot(kontonummer)){
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
int beloppInput(){
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
