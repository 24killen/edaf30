#ifndef KUND_H
#define KUND_H
#include <random>
#include <time.h>

class Kund
{
    int atid; // Ankomsttid
    int btid; // Betjäningstid
    public:
        Kund(int a);
        virtual ~Kund();
        int getATid();
        int getBTid();
        bool isDone(int time = 1);
    protected:
    private:
};
#endif // KUND_H
