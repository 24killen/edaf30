#include "Bank.h"

using namespace std;

Bank::Bank(string fil)
{
    vector<Konto> konton;
    nastaKontonummer = 1;
    filnamn = fil;
    ladda();
}

Bank::~Bank()
{

}

// En metod som används för att spara all data till en fil.
void Bank::spara(){
    ofstream output;
    output.open(filnamn);
    for(int i = 0; i < antalKonton; i++){
        output<< konton.at(i).getKontonummer() << endl;
        output << konton.at(i).getKontoinnehavare() << endl;
        output<< konton.at(i).getKontotyp() << endl;
        output<< konton.at(i).getSaldo() << endl;
    }
    output.close();
}

// En metod som används för att ladda all data från fil till hela systemet.
// Skapar konton och lägger in dessa i vektorn konton enligt den externa filens innehåll.
// Använder sedan även en annan metod för att bestämma nästa tillgängliga kontonummer.
void Bank::ladda(){
    ifstream input;
    input.open(filnamn);
    if(!input.fail()){
        string text, nyckelord, kontoinnehavare;
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

// Privat metod som används av den publika metoden med samma namn.
// Metoden skapar ett nytt konto med den korrekta inmatningen och
// sparar detta i den statiska vektorn "konton".
int Bank::skapaKonto(string kontoinnehavare, char kontotyp){
    Konto k(kontoinnehavare, nastaKontonummer++, kontotyp);
    konton.push_back(k);
    antalKonton++;
    spara();
    cout << "Kontot skapades med kontonummer " << (nastaKontonummer-1) << "." << endl;
    return nastaKontonummer-1;
}

// Privat metod som sätter in det korrekta belopped till det korrekta kontot.
void Bank::sattIn(int kontonummer, int belopp){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).sattIn(belopp);
    spara();
}

// Tar ut en specifik summa pengar från ett specifikt konto
void Bank::taUt(int kontonummer, int belopp){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).taUt(belopp);
    spara();
}

// Hämtar saldot för ett specifikt konto.
int Bank::saldo(int kontonummer){
    int index = hamtaKontoIndex(kontonummer);
    int saldo = konton.at(index).getSaldo();
    return saldo;
}

// Skriver ut all information om alla konton som finns i systemet.
void Bank::printInfoFranAlla(){
    cout << "Information fran alla konton: " << endl;
    cout << "__________________________________________" << endl;
    for(int i = 0; i < antalKonton; i++){
        printInfo(i);
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

// Tar bort ett specifikt konto från vektorn konton.
void Bank::taBort(int kontonummer){
    int index = hamtaKontoIndex(kontonummer);
    konton.erase(konton.begin()+index);
    antalKonton--;
    spara();
    cout << "Kontot med kontonummer " << kontonummer << " ar nu avslutat (borttaget)." << endl;
}

// En metod för att kontrollera och hantera ändringar av kontoinnehavaren för ett specifikt konto.
void Bank::modifieraKontoinnehavare(int& kontonummer, string& namn){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).setKontoinnehavare(namn);
    spara();
}

// En metod för att kontrollera och hantera ändringar av kontotypen för ett specifikt konto.
void Bank::modifieraKontotyp(int kontonummer, char typ){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).setKontotyp(typ);
    spara();
}

// Skriver ut informationen för ett konto med index "i" från vektorn "konton".
void Bank::printInfo(int i){
    cout << "Kontoinnehavare: " << konton.at(i).getKontoinnehavare() << endl;
    cout << "Kontonummer: " << konton.at(i).getKontonummer() << endl;
    cout << "Kontotyp: " << konton.at(i).getKontotyp() << endl;
    cout << "Saldo: " << konton.at(i).getSaldo() << endl;
    cout << "__________________________________________" << endl;
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
