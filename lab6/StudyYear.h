#pragma once
#include <istream>
using ::std::istream;

#include <ostream>
using ::std::ostream;

class StudyYear{
public:
    int value;

public:
    StudyYear();
    StudyYear(int);

    StudyYear& operator++ ();
    StudyYear operator++ (int);
    
    StudyYear& operator-- ();
    StudyYear operator-- (int);

    bool operator== (const StudyYear&);
    bool operator< (const StudyYear&);

    operator int();

    friend istream& operator>> (istream&, StudyYear&);
    friend ostream& operator<< (ostream&, const StudyYear&);
};