#include "Mynt.h"

std::default_random_engine Mynt::re(time(NULL));
std::uniform_int_distribution<int> Mynt::flip{0, 1};

Mynt::Mynt(){
    kasta();
}

Mynt::~Mynt(){
}

void Mynt::kasta(){
    if(flip(re) == 0)
        sida = Krona;
    else
        sida = Klave;
}

void Mynt::visa(){
    std::string data = "Klave";
    if(sida == Krona)
        data = "Krona";
    std::cout << data << std::endl;
}

Mynt::Myntsida Mynt::uppsida(){
    return sida;
}
