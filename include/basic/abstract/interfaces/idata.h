#ifndef IDATA_H
#define IDATA_H

#include "basic/basictypes.h"

#include <vector>

class IData
{
protected:
    std::vector<byte_t> m_bytes;

public:
    virtual bool setBytes(byte_t* data, int num) = 0;
    virtual void setBytesVec(const std::vector<byte_t> &bytesVec) = 0;
    virtual const byte_t *getBytes() = 0;
    virtual const std::vector<byte_t> &getBytesVec() const = 0;
};

#endif
