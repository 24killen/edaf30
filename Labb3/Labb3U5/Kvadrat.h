#ifndef KVADRAT_H
#define KVADRAT_H


class Kvadrat
{
    public:
        friend class Kvadrat;
        Kvadrat();
        Kvadrat(int side);
        virtual ~Kvadrat();
        int area();
        int operator++() ;
        int operator--() ;
        int operator+=(int a) ;
        int operator-=(int a) ;
        int operator<(Kvadrat k);
        int operator>(Kvadrat k);
        bool operator==(Kvadrat k);
    protected:
    private:
        int side;
};

#endif // KVADRAT_H
