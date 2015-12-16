#ifndef PET_H
#define PET_H


class Pet
{
    public:
        Pet();
        virtual ~Pet();
        Pet(const Pet& other);
        Pet& operator=(const Pet& other);
    protected:
    private:
};

#endif // PET_H
