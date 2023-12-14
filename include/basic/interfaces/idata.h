#ifndef IDATA_H
#define IDATA_H

#include "../../../include/basic/basictypes.h"

class IData
{
public:
    virtual void setData(const void* data, uint_t size) = 0;
    virtual void data(void* data, uint_t size) const = 0;
};

#endif
