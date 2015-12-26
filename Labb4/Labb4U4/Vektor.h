#ifndef VEKTOR_H
#define VEKTOR_H
#include <stdexcept>

class Vektor{
    public:
        Vektor(int l = 10) : p{(new int[l])}, ant{l} {}
        virtual ~Vektor() {delete p;}
        int lngd() const {return ant;}
        int& operator[](int i){if(i>=ant){throw std::invalid_argument("Value is over the nbr of slots");}else{return p[i];}}
    protected:
    private:
        int *p;
        int ant;
};

#endif // VEKTOR_H
