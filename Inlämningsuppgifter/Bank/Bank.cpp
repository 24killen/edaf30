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

// En metod som anv�nds f�r att spara all data till en fil.
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

// En metod som anv�nds f�r att ladda all data fr�n fil till hela systemet.
// Skapar konton och l�gger in dessa i vektorn konton enligt den externa filens inneh�ll.
// Anv�nder sedan �ven en annan metod f�r att best�mma n�sta tillg�ngliga kontonummer.
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

// Privat metod som anv�nds av den publika metoden med samma namn.
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

// Privat metod som s�tter in det korrekta belopped till det korrekta kontot.
void Bank::sattIn(int kontonummer, int belopp){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).sattIn(belopp);
    spara();
}

// Tar ut en specifik summa pengar fr�n ett specifikt konto
void Bank::taUt(int kontonummer, int belopp){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).taUt(belopp);
    spara();
}

// H�mtar saldot f�r ett specifikt konto.
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

// Skriver ut information p� alla konton som �gs av samma kontoinnehavare.
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

// Tar bort ett specifikt konto fr�n vektorn konton.
void Bank::taBort(int kontonummer){
    int index = hamtaKontoIndex(kontonummer);
    konton.erase(konton.begin()+index);
    antalKonton--;
    spara();
    cout << "Kontot med kontonummer " << kontonummer << " ar nu avslutat (borttaget)." << endl;
}

// En metod f�r att kontrollera och hantera �ndringar av kontoinnehavaren f�r ett specifikt konto.
void Bank::modifieraKontoinnehavare(int& kontonummer, string& namn){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).setKontoinnehavare(namn);
    spara();
}

// En metod f�r att kontrollera och hantera �ndringar av kontotypen f�r ett specifikt konto.
void Bank::modifieraKontotyp(int kontonummer, char typ){
    int index = hamtaKontoIndex(kontonummer);
    konton.at(index).setKontotyp(typ);
    spara();
}

// Skriver ut informationen f�r ett konto med index "i" fr�n vektorn "konton".
void Bank::printInfo(int i){
    cout << "Kontoinnehavare: " << konton.at(i).getKontoinnehavare() << endl;
    cout << "Kontonummer: " << konton.at(i).getKontonummer() << endl;
    cout << "Kontotyp: " << konton.at(i).getKontotyp() << endl;
    cout << "Saldo: " << konton.at(i).getSaldo() << endl;
    cout << "__________________________________________" << endl;
}

// Letar upp p� vilket index i vektorn koton d�r ett specifikt kontonummer finns.
// Om kontonumret inte finns s� returneras -1
// Annars returneras index f�r det kontonumret.
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

// En enkel hj�lpmetod f�r att skriva ut tillg�ngliga kontotyper.
void Bank::printTillgangligaTyper(){
        cout << endl;
        cout << "Tillgangliga typer:" << endl;
        cout << "S - Sparkonto" << endl;
        cout << "T - Transaktionskonto" << endl << endl;
}
