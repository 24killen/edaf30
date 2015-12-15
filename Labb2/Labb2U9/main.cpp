#include <iostream>

using namespace std;


void strncat(char *dest, const char *src, size_t n){

    int start;
    for(start = 0; dest[start]!= NULL; ++start){
    }
//    cout << "Start at: " << start << endl;
    int stop = start+n;
    for(int i=start;i<stop;++i){
        dest[i] = src[i-start];
//        cout << dest[i];
    }

}


int main(){
    char dest[81] = {0}, src[81] = {0};
    int lenght;
    cin.getline(dest, 80);
    cin.getline(src,80);
    cin >> lenght;
    strncat(&dest[0], &src[0], lenght);

    for(int i=0;i<sizeof(dest);++i){
        cout << dest[i];
    }
    cout << endl;
    return 0;
}
