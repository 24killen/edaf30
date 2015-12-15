#ifndef MYNT_H
#define MYNT_H

#include <random>
#include <ctime>
#include <iostream>

class Mynt{
    public:
        enum Myntsida {Krona, Klave};
        Mynt();
        virtual ~Mynt();
        void kasta();
        void visa();
        Myntsida uppsida();
    protected:
    private:
        static std::default_random_engine re;
        static std::uniform_int_distribution<int> flip;
        Myntsida sida;
};

#endif // MYNT_H
