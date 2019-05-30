#ifndef CAR_H
#define CAR_H

#include "Insurance.h"

class Car : public Insurance{
public:
    virtual void Calculate() override;
};

#endif