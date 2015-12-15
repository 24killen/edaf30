#include <iostream>

using namespace std;

void strreverse(char *s, size_t n){
    int last = 0, first = n-1;
    for(int i=1;last<first;++i){
        char temp = s[last];
        s[last] = s[first];
        s[first] = temp;
        last+=1;
        first-=1;
    }
}

int main(){
    int lenght = 6;
//    cout << "Mata in tallängden: ";
//    cin >> lenght;
    lenght++;
    char tal[lenght+1];
    cout << "Mata in talet: ";
    cin.getline(tal,lenght);
    char* s = &tal[0];
    strreverse(s, lenght);
    for(int i=0;i<lenght;++i){
        cout << tal[i];
    }
//    cout << "Hello world!" << endl;
    return 0;
}
