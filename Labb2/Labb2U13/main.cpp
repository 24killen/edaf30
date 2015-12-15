#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL)*time(NULL));
    int rad[4][4] = {0};
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            rad[i][j] = rand()%16;
        }
    }

     for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cout << rad[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
