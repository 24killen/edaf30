#include <iostream>
#include <vector>
using namespace std;

void addOne(vector<int> &vec){
    int lenght = vec.size();
    for(int i=0; i<lenght;++i){
        ++vec[i];
    }
}

int main()
{
    vector<int> vec = {0,1,2,3,4,5};
    addOne(vec);
    for(int i=0;i<vec.size();++i){
        cout << vec[i];
    }
    cout << endl;
    return 0;
}
