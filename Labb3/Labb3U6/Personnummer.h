#ifndef PERSONNUMMER_H
#define PERSONNUMMER_H
#include <iostream>

class Personnummer
{
    public:
        Personnummer();
        virtual ~Personnummer();
        bool operator!();
    protected:
    private:
        bool validate();
        friend std::ostream& operator<<(std::ostream& out, const Personnummer& pNbr);
        friend std::istream& operator>>(std::istream& in,Personnummer& pNbr);
        char persNbr[11];
        bool pNbrOK;
};
std::ostream& operator<<(std::ostream& out, const Personnummer& pNbr);
std::istream& operator>>(std::istream& in,Personnummer& pNbr);

#endif // PERSONNUMMER_H
