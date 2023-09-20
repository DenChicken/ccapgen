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
    virtual void setBytes(const std::vector<byte_t> &bytesVec) = 0;
    virtual void bytes(byte_t* retData, int num) = 0;
    virtual void bytes(std::vector<byte_t>& retVec) = 0;
};

#endif
