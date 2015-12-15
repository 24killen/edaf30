#include <iostream>

using namespace std;

class Rektangel{
    int length, width;

public:
    void sattVarden(int l, int w){
        length = l;
        width = w;
    }

    int area(){
        return length * width;
    }

    void visa(){
        cout << "L�ngd: " << length << endl << "Bredd: " << width << endl;
    }

    int omkrets(){
        return (length+width)*2;
    }

    void forstora(int factor){
        length *= factor;
        width *= factor;
    }

};

int main(){
    int l, w, factor;

    cout << "Skriv in l�ngd och sen bredd" << endl;
    cin >> l;
    cin >> w;

    Rektangel rek;
    rek.sattVarden(l, w);
    cout << "Area: " << rek.area() << endl;
    cout << "Omkrets: " << rek.omkrets() << endl;
    rek.visa();

    cout << endl << "F�rstora med: ";
    cin >> factor;
    rek.forstora(factor);

    cout << endl << "F�rstorade med " << factor << endl;
    cout << "Area: " << rek.area() << endl;
    cout << "Omkrets: " << rek.omkrets() << endl;
    rek.visa();





    return 0;
}
