#include "Test.h"
#include "Bank.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}

void Test::startaTest(){

    string filename = "Banksystem-test.txt";
    ifstream file;

    /* En extra funktion som av någon anledning inte längre fungerar..
    file.open(filename);
    if(!file.fail()){
        cout << "Vill du ta bort test-filen " << filename  << "? (Y/n): " << endl;
        string input;
        getline(cin,input);
        if(input == "y" ||input == "Y"){
            remove(filename.c_str());
        }
    }
    file.close();
    */

    Bank b(filename);
    vector<string> users = {"Bob","Kevin","Stuart"};
    vector<char> types = {'S','T'};

    int konto = 0;
    int tmp = 0;
    int tmp2 = 0;
    int sum = 0;
    int rand_int = 0;
    string name;

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        konto = b.skapaKonto(users.at(tmp),types.at(tmp2));
        cout << "Kontoinnehavare: " << users.at(tmp) << endl;
        cout << "Nuvarande saldo (" << b.saldo(konto) << "kr)" << endl;
        rand_int = rand()%3;
        for(int j = 0; j < rand_int; j++){
            sum = rand();
            cout << "Satter in: " << sum << "kr. ";
            b.sattIn(konto,sum);
            cout << "Saldo: " << b.saldo(konto) << "kr" << endl;
            sum = rand();
            cout << "Tar ut: " << sum << "kr. ";
            b.taUt(konto,sum);
            cout << "Saldo: " << b.saldo(konto) << "kr" << endl;
        }
        cout << "Nuvarande saldo (" << b.saldo(konto) << "kr)" << endl;

        if(rand()%4==0){
            name = users.at(tmp) + "-modified";
            b.modifieraKontoinnehavare(konto,(name));
            cout << "Modifierade kontoinnehavare" << endl;
            cout << "Ny kontoinnehavare: " << name << endl;
        }

        cout << "__________________________________________" << endl;
        if(++tmp == users.size())
            tmp = 0;
        if(++tmp2 == types.size())
            tmp2 = 0;
    }
    cout << "Vill du skriva ut info for alla konton? (Y/n): " << endl;
    string input;
    getline(cin,input);
    if(input == "y" ||input == "Y"){
        b.printInfoFranAlla();
    }

   // b.printInfoFranAlla();
}
