#ifndef WORD_H
#define WORD_H


class Word{
    public:
        Word(const Word &w): Word(w.swedish, w.english){};  //Copy-konstruktor
        Word(const char *sw, const char *eng);              //Konstruktor
        virtual ~Word();                                    //Destruktor
        const char *get_sw() const;
        const char *get_eng() const;
    protected:
    private:
        char *swedish;
        char *english;
};

#endif // WORD_H
