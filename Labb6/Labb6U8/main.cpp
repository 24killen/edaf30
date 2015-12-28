#include <iostream>
#include <sstream>
using namespace std;

union Data{
    unsigned int four_bytes;
    unsigned short twoBytes[2];
    unsigned char oneByte[4];
};

int main(){
    stringstream ss1, ss2, ss3, ss4;        //hex-converter
    int theNbr = 305419896;    //the hex is 12345678
    Data memory;
    string result;
    ss1<<hex<<theNbr;
    cout<<"Original: "<<ss1.str()<<endl;

    memory.four_bytes = theNbr;
    ss2<<hex<<memory.four_bytes;
    cout<<"Result 1: "<<ss2.str()<<endl;


    memory.twoBytes[0] = theNbr&0x0ffff;
    memory.twoBytes[1] = theNbr>>16;
    ss3<<hex<<memory.twoBytes[0]<<" ";
    ss3<<hex<<memory.twoBytes[1];
    cout<<"Result 2: "<<ss3.str()<<endl;


    memory.oneByte[0] = theNbr&0x0ff;
    memory.oneByte[1] = theNbr>>8;
    memory.oneByte[2] = theNbr>>16;
    memory.oneByte[3] = theNbr>>24;
    ss4<<hex<<(int)memory.oneByte[0]<<" ";   //12(hex) = <->(ASCII)
    ss4<<hex<<(int)memory.oneByte[1]<<" ";   //34(hex) = 4(ASCII)
    ss4<<hex<<(int)memory.oneByte[2]<<" ";   //56(hex) = V(ASCII)
    ss4<<hex<<(int)memory.oneByte[3]<<" ";   //78(hex) = x(ASCII)
    cout<<"Result 3: "<<ss4.str()<<endl;

    return 0;
}


