#include <iostream>

using namespace std;

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


int main()
{
    int val = -1;
    string dummy;
    while(val!=0){
        printMenu();
        if(cin >> val){ // If the input is an int
            switch(val){
                case 0: // Avsluta programmet
                    break;
                case 1: // Skapa konto
                    break;
                case 2: // Insattning av belopp till konto
                    break;
                case 3: // Uttag av belopp fran konto
                    break;
                case 4: // Fraga om saldo for konto
                    break;
                case 5: // Lista information for alla konton
                    break;
                case 6: // Lista information for alla konton for en viss kontoinnehavare
                    break;
                case 7: // Avsluta (ta bort) ett existerande konto
                    break;
                case 8: // Modifiera ett existerande konto
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
