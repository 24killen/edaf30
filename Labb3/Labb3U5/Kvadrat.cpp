#include "Kvadrat.h"

Kvadrat::Kvadrat()
{
    side = 1;
}
Kvadrat::Kvadrat(int a)
{
    side = a;
}

Kvadrat::~Kvadrat()
{
    //delete side;
}

int Kvadrat::area()
{
    return side*side;
}

int Kvadrat::operator++()
{
    return side++;
}

int Kvadrat::operator--()
{
    if(side--<0)
        side = 0;
    return side;
}

int Kvadrat::operator+=(int a)
{
    return side += a;
}

int Kvadrat::operator-=(int a)
{
    side -= a;
    if(side<0){
        side = 0;
    }
    return side;
}

int Kvadrat::operator<(Kvadrat k){
    if(side<k.side){
        return 1;
    }
    else if(side==k.side){
        return 0;
    }
    else{
        return -1;
    }
}
int Kvadrat::operator>(Kvadrat k){
    return (operator<(k)*(-1));
}

bool Kvadrat::operator==(Kvadrat k){
    return side == k.side;
}
