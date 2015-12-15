#include <iostream>

using namespace std;

int mystrncmp(const char* s1, const char* s2, size_t n){


    for(int i=0;i<n;++i){
        if(s1[i]<s2[i])
            return -1;
        else if (s1[i]>s2[i])
            return 1;
        else
            continue;
    }
    return 0;
}

int main(){

    char text1[81] = {0}, text2[81] = {0};

    cin.getline(text1,80);
    cin.getline(text2,80);
    char* t1 = &text1[0];
    char* t2 = &text2[0];

    cout << mystrncmp(t1,t2,80);
    return 0;
}
