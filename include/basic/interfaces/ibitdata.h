#ifndef IDATA_H
#define IDATA_H

#include "../../../include/basic/basictypes.h"

class IBitData
{
public:
    virtual void setData(const void* data, uint_t bits) = 0;
    virtual void data(void* data) const = 0;
    virtual uint_t bitsNum() const = 0;
    virtual uint_t bytesNum() const = 0;
};

#endif
