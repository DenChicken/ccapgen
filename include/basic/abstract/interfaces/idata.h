#ifndef IDATA_H
#define IDATA_H

#include "basic/basictypes.h"

#include <vector>

class IData
{
private:
    std::vector<byte_t> m_bytes;

public:
    virtual bool setBytes(byte_t* data, int num) = 0;
    virtual bool setBytesVec(const std::vector<byte_t> &bytesVec, int num) = 0;
    virtual const byte_t *getBytes() const = 0;
    virtual const std::vector<byte_t> &getBytesVec() const = 0;
    virtual bool insertBytes(byte_t* data, int num) = 0;
    virtual bool appendBytes(byte_t* data, int num) = 0;
};

#endif IDATA_H
