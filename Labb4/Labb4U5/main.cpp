#include <iostream>
#include <fstream>

using namespace std;

int main(){

//    ofstream file1("Test1");
//    ofstream file2("Test2");
//    char temp[10] = {"test"};
//    for(int i=0;i<10;++i){
//        file1.put(temp[i]);
//        file2.put(temp[i]);
//    }
//    file1.close();
//    file2.close();

    char fileName1[100], fileName2[100];
    string content1, content2;
    char c;
    cout << "Ange första filens namn: ";
    cin >> fileName1;
    cout << "Ange andra filens namn: ";
    cin >> fileName2;


    ifstream f1(fileName1);
    while(f1.get(c)){
        content1.push_back(c);
    }
    f1.close();
    ifstream f2(fileName2);
    while(f2.get(c)){
        content2.push_back(c);
    }
    f2.close();

//    cout << "Fil 1: " << content1 << endl << "Fil 2: " << content2 << endl;
    if(content1.compare(content2)==0){
        cout << "Filerna är identiska";
    }
    else{
        cout << "Filerna är inte lika";
    }
    return 0;
}
