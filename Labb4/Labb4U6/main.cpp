#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string namn;
    int counter = 0;
    char c;

    ifstream f1("namnlista.txt");
    ofstream f2("email.txt");
    f2.clear();
    cout << "enter while" << endl;
    while(f1.get(c)){
            if(c!=' '&&c!='\n'){
                namn.push_back(c);
               cout << c;
//                ++counter;
                }
            else if (c==' '){
                namn.push_back('.');
//                counter = 0;
                // for-sats fr att lägga in bokstäverna i filen
                cout << "enter for1" << endl;
                for(int i=0;i<namn.length();++i){
                    f2.put(namn.at(i));
                    cout << namn.at(i);
                }
                namn.clear();
                continue;
            }
            else{
                //nästa namn
                namn.append("@gronkoping.se");
                cout << "enter for2";
                for(int i=0;i<namn.length();++i){
                    f2.put(namn.at(i));
                    cout << namn.at(i);
                }
                f2.put('\n');
                namn.clear();
            }
    }
    f1.close();
    f2.close();
    //char temp[100] = {(fornamn)};

//    for(int i=0;i<10;++i){
//        file1.put(temp[i]);
//        file2.put(temp[i]);
//    }
//    file1.close();
//    file2.close();


    return 0;
}
