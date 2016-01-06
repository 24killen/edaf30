#include "Bank.h"

using namespace std;

Bank::Bank(string fil)
{
    vector<Konto> konton;
    nastaKontonummer = 1;
    filnamn = fil;
    ifstream input;
    ofstream output;
    ladda();
}

Bank::~Bank()
{

}

void Bank::spara(){
    output.open(filnamn);
    for(int i = 0; i < antalKonton; i++){
        output<< konton.at(i).getKontonummer() << endl;
        output << konton.at(i).getKontoinnehavare() << endl;
        output<< konton.at(i).getKontotyp() << endl;
        output<< konton.at(i).getSaldo() << endl;
    }
    output.close();
}

void Bank::ladda(){
    ifstream fileExists(filnamn);
    if(fileExists){
        input.open(filnamn);
        string text;
        string nyckelord;

        string kontoinnehavare;
        int kontonummer,saldo;
        char kontotyp;
        bool fortsatt = true;

        while(input.good()){
            getline(input,text);
            if(text != ""){
                kontonummer = atoi(text.c_str());

                getline(input,text);
                kontoinnehavare = text;

                getline(input,text);
                kontotyp = text.c_str()[0];

                getline(input,text);
                saldo = atoi(text.c_str());

                Konto k(kontoinnehavare,kontonummer,kontotyp);
                k.sattIn(saldo);
                antalKonton++;

                konton.push_back(k);
            }else{
                fortsatt = false;
            }

        }
        input.close();
        fileExists.close();
    }
    nastaKontonummer = hamtaStorstaKontonummer();
}

int Bank::hamtaStorstaKontonummer(){
 int tmp = nastaKontonummer;
 int highestNumber = tmp;
    for(int i = 0; i < antalKonton; i++){
        tmp = konton.at(i).getKontonummer()+1;
        if(tmp > highestNumber){
            highestNumber = tmp;
        }
    }
    return highestNumber;
}

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
        printTillgangligaTyper();

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
    skapaKonto(kontoinnehavare, kontotyp);
}

// Privat metod som används av den publika metoden med samma namn.
// Metoden skapar ett nytt konto med den korrekta inmatningen och
// sparar detta i den statiska vektorn "konton".
void Bank::skapaKonto(string kontoinnehavare, char kontotyp){
    Konto k(kontoinnehavare, nastaKontonummer++, kontotyp);
    konton.push_back(k);
    antalKonton++;
    spara();
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
    spara();
}

// Hanterar inmatningen för att ta ut en specifik
// summa pengar från ett specifikt konto.
void Bank::taUt(){
    int kontonummer = kontonummerInput();
    if(kontonummer != 0){
        int belopp = beloppInput();
        while(belopp<0){
            cout << "Du kan inte ta ut mindre an 0 kr pa ditt konto. Forsok igen." << endl;
            belopp = beloppInput();
        }
        taUt(kontonummer, belopp);
    }
}

// Tar ut en specifik summa pengar från ett specifikt konto
void Bank::taUt(int kontonummer, int belopp){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).taUt(belopp);
    spara();
}

// Hanterar inmatning för att hämta saldot för ett specifikt konto.
void Bank::saldo(){
    int kontonummer = kontonummerInput();
    if(kontonummer != 0){
        saldo(kontonummer);
    }
}

// Skriver ut saldot för ett specifikt konto.
void Bank::saldo(int kontonummer){
    int index = hamtaKontoIndex(kontonummer);
    int saldo = konton.at(index).getSaldo();
    cout << "Saldot for kontonummer " << kontonummer << " ar: " << saldo << endl;
}

// Skriver ut all information om alla konton som finns i systemet.
void Bank::printInfoFranAlla(){
    cout << "Information fran alla konton: " << endl;
    cout << "__________________________________________" << endl;
    for(int i = 0; i < antalKonton; i++){
        printInfo(i);
    }
}

// Hanterar inmatningen för att skriva ut vilka konton som ägs av samma kontoinnehavare.
void Bank::printInfoFranAllaMedNamn(){
    string namn;
    string dummy;
    bool korrekt = false;
    while(!korrekt){
        cout << "Namn: ";
        if(cin >> namn){
            korrekt = true;
            printInfoFranAllaMedNamn(namn);
        }else{
            cin.clear();
            cin >> dummy;
            cout << "Felaktig inmatning for namn, forsok igen." << endl;
        }
    }
}
// Skriver ut information på alla konton som ägs av samma kontoinnehavare.
void Bank::printInfoFranAllaMedNamn(string namn){
    int antalKontonForNamn = 0;
    for(int i = 0; i < antalKonton; i++){
        if(compareStringsIgnoreCase(namn, konton.at(i).getKontoinnehavare())){
            if(antalKontonForNamn == 0){
                cout << "Alla konton for " << namn << ":"<<endl;
                cout << "__________________________________________" << endl;
            }
            printInfo(i);
            antalKontonForNamn++;
        }
    }
}

// Hanterar inmatning och bekräftelse för att ta bort ett konto.
void Bank::taBort(){
    int kontonummer = kontonummerInput();
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
                    taBort(kontonummer);
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

// Tar bort ett specifikt konto från vektorn konton.
void Bank::taBort(int kontonummer){
    int index = hamtaKontoIndex(kontonummer);
    konton.erase(konton.begin()+index);
    antalKonton--;
    spara();
    cout << "Kontot med kontonummer " << kontonummer << " ar nu avslutat (borttaget)." << endl;
}

// Visar en meny och hanterar inmatning för denna.
// Startar olika funktioner beroende på menyval.
void Bank::modifiera(){
    int kontonummer = kontonummerInput();
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
                modifieraKontoinnehavare(kontonummer);
                break;
            case 2:
                modifieraKontotyp(kontonummer);
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

// En metod för att kontrollera och hantera ändringar av kontoinnehavaren för ett specifikt konto.
void Bank::modifieraKontoinnehavare(int kontonummer){
    bool korrekt = false;
    string namn, dummy;
    int index = hamtaKontoIndex(kontonummer);
    while(!korrekt && kontonummer != 0){
        cout << "Nytt namn: ";
        if(cin >> namn){
            korrekt = true;
            konton.at(index).setKontoinnehavare(namn);
            spara();
        }else{
            cin.clear();
            cin >> dummy;
            cout << "Felaktig inmatning for andring av kontoinnehavare, forsok igen." << endl;
        }
    }
}

// En metod för att kontrollera och hantera ändringar av kontotypen för ett specifikt konto.
void Bank::modifieraKontotyp(int kontonummer){
    bool korrekt = false;
    char typ, dummy;
    int index = hamtaKontoIndex(kontonummer);
    while(!korrekt && kontonummer != 0){
        printTillgangligaTyper();
        cout << "Kontotyp: ";
        if(cin >> typ){
            typ = toupper(typ);
            if(typ == 'S' || typ == 'T' ){
                korrekt = true;
                konton.at(index).setKontotyp(typ);
                cin.sync();
                spara();
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

// Skriver ut informationen för ett konto med index "i" från vektorn "konton".
void Bank::printInfo(int i){
    cout << "Kontoinnehavare: " << konton.at(i).getKontoinnehavare() << endl;
    cout << "Kontonummer: " << konton.at(i).getKontonummer() << endl;
    cout << "Kontotyp: " << konton.at(i).getKontotyp() << endl;
    cout << "Saldo: " << konton.at(i).getSaldo() << endl;
    cout << "__________________________________________" << endl;
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

// Letar upp på vilket index i vektorn koton där ett specifikt kontonummer finns.
// Om kontonumret inte finns så returneras -1
// Annars returneras index för det kontonumret.
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

// Compares two strings (non case sensitive) and returns true if
// they are equal. Or false if they don't match.
// This method is inspired by PiotrNycz on stackoverflow.
// Source: http://stackoverflow.com/a/12568507
bool Bank::compareStringsIgnoreCase(string str1, string str2){
    if(str1.length() == str2.length()){
        for(int i=0; i<str1.length(); i++){
            if(toupper(str1[i]) != toupper(str2[i])){
                return false;
            }
        }
        return true;
    }
    return false;
}

// En enkel hjälpmetod för att skriva ut tillgängliga kontotyper.
void Bank::printTillgangligaTyper(){
        cout << endl;
        cout << "Tillgangliga typer:" << endl;
        cout << "S - Sparkonto" << endl;
        cout << "T - Transaktionskonto" << endl << endl;
}
