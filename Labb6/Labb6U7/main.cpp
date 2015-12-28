#include <iostream>

using namespace std;

unsigned int packedDate(int year, int month, int day){
    unsigned int packedData;
    packedData:16;
    packedData = year << 9;
    packedData += month << 5;
    packedData += day;
    return packedData;
}

void unpackDate(unsigned int packedData, int* date){
    int temp = packedData & 0b1111111000000000;
    temp = temp >> 9;
    date[0] = temp;
    temp = packedData & 0b0000000111100000;
    temp = temp >> 5;
    date[1] = temp;
    date[2] = packedData & 0b0000000000011111;
}

int main(){

    cout<<packedDate(99,12,31)<<endl;
    int data[3];
    unpackDate(51103, data);
    for(int i=0;i<3;++i){
        cout<<data[i]<<endl;
        //++date;
    }
    return 0;
}
