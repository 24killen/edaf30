#ifndef TRACK_H
#define TRACK_H


class Track{

    public:
        Track(int trackLenght = 1000) {lenght = trackLenght; position = 0;}
        virtual ~Track(){}
        Track(const Track& other);
        Track& operator=(const Track& other);
        bool reachedGoal();
        int getLenght();
        int getCurrentPosition();
        void movement(int nbrOfSteps);

    protected:
    private:
        int position;
        int lenght;
};

#endif // TRACK_H
