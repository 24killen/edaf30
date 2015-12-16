#ifndef FILEDATA_H
#define FILEDATA_H

// Collects data for character category
class StatElement
{
public:
	StatElement(int l = 0, int h = 0, double r = 0.0) : low(l), high(h), rate(r) {;}
	unsigned int low;
	unsigned int high;
	double rate;
};



// Reads and collects data for all character categories
class FileData
{
    public:

        // Initialize data structures to the initial state:
        FileData();


    private:

};

#endif // FILEDATA_H
