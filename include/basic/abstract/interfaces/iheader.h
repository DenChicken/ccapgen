#ifndef IHEADER_H
#define IHEADER_H

#include "basic/headercud.h"

#include <vector>
#include <map>

class IHeader
{
protected:
    HeaderCUD m_CUD;
    std::map<uint8_t, std::vector<byte_t>> m_fields;

public:
    virtual bool setField(uint8_t pos, byte_t* data) = 0;
    virtual bool setFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) = 0;
    virtual bool insertField(uint8_t pos, byte_t* data) = 0;
    virtual bool insertFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) = 0;
    virtual bool appendField(byte_t *data) = 0;
    virtual bool appendFieldVec(byte_t* data) = 0;
};

#endif
