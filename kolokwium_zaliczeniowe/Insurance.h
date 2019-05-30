#ifndef INSURANCE_H
#define INSURANCE_H

class Insurance{
public:
    virtual ~Insurance() {}
    virtual void Calculate() = 0;
};

#endif