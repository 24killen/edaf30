#ifndef PET_H
#define PET_H
#include <string>

using namespace std;

class Pet{
    public:
        Pet(string s) : sound(s){};
        virtual ~Pet();
        Pet(const Pet& other);
        Pet& operator=(const Pet& other);
        virtual string speak(){}
    protected:
        string sound;
    private:

};

#endif // PET_H
