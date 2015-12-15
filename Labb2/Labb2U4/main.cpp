#include <iostream>

using namespace std;

char* downcase(char* text){
    for(int i=0;i<sizeof(text); ++i){
        text[i] = tolower(text[i]);
    }
    return text;
}

int main(){
    char text[81];
    char* arrays = &text[0];
    cin.getline(text, 81);

    downcase(arrays);
    cout << text << endl;
    return 0;
}
