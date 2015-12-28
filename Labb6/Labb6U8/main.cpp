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
    int theNbr = 12345678;    //the hex if 0x0fedc, 65244
    Data memory;
    string result;
    ss1<<hex<<theNbr;
    cout<<"TheNbr: "<<ss1.str()<<endl;

    memory.four_bytes = theNbr;
    ss2<<hex<<memory.four_bytes;
    cout<<"Result 1: "<<ss2.str()<<endl;


    memory.twoBytes[0] = theNbr>>12;
    memory.twoBytes[1] = theNbr&0x0fff;
    ss3<<hex<<memory.twoBytes[0];
    ss3<<hex<<memory.twoBytes[1];
    cout<<"Result 2: "<<ss3.str()<<endl;




//    memory.oneByte[0] = theNbr & (0xf000>>i);
//        cout<<memory.oneByte[i]<<endl;

    int sum = 0;
    for(int i=0;i<4;++i){
        sum += memory.oneByte[i];
    }
//    cout<<sum;
    return 0;
}


