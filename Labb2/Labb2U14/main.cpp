#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL)*time(NULL));
    int rad[4][4] = {0};
    int x =0; int y=0;

    for(int i=0;i<16;++i){
            for(int j=0;rad[x][y]!=0;++j){
                x = rand()%4;
                y = rand()%4;
            }
        rad[x][y] = i;
    }

     for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
                if(rad[i][j]==0){
                    x=i;
                    y=j;
                }
            cout << rad[i][j] << " ";
        }
        cout << endl;
    }
    bool completed = false;
    while(!completed){
        int val = -1;
        bool moved = false;
        cin >> val;

        if(val>-1 && val<16){
//            cout << ".";
            for(int i=x-1;i<=x+1&&!moved;i+=2){
                if(i<0 || i>4)
                    continue;
                else if(rad[i][y] == val){
                    rad[x][y] = val;
                    rad[i][y] = 0;
                    x=i;
                    moved = true;
                }
            }
//        cout << ";";
            for(int i=y-1;i<=y+1&&!moved;i+=2){
                if(i<0 || i>4)
                    continue;
                else if(rad[x][i] == val){
                    rad[x][y] = val;
                    rad[x][i] = 0;
                    y=i;
                    moved = true;
                }
//                cout << "+";
            }

        if(moved == false)
            cout << "Ingen giltigt drag" << endl;
//        cout << "-";
        //kontrollen
        completed = true;
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                if(rad[i][j]!=i*4+j){
                    completed = false;
                }
            }
        }
      }
        else{
            cout << "felaktig inmatning"<<endl;
        }
             for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
                if(rad[i][j]==0){
                    x=i;
                    y=j;
                }
            cout << rad[i][j] << " ";
        }
        cout << endl;
        }
    }
 cout << "Grattis!!!!!!";
    return 0;
}
