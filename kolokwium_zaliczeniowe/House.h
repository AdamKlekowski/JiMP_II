#ifndef HOUSE_H
#define HOUSE_H

#include "Insurance.h"

class House : public Insurance{
public:
    virtual void Calculate() override;
};

#endif