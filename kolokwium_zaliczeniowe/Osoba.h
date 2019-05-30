#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>

class Osoba{
private:
    std::string name;
    std::string surname;
    int age;

public:
    Osoba();
    Osoba(std::string, std::string, int);

    Osoba& operator++ ();
    bool operator== (const Osoba&);
    friend std::istream& operator>> (std::istream&, Osoba&);
    friend std::ostream& operator<< (std::ostream &output, const Osoba&);
};

#endif