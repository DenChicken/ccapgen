#ifndef IHEADER_H
#define IHEADER_H

#include "basic/headercud.h"

#include <vector>
#include <map>

class IHeader
{
protected:
    typedef uint8_t fID_t;

    HeaderCUD m_CUD;
    std::map<fID_t, std::vector<byte_t>> m_fields;

public:
    virtual bool setField(fID_t fieldId, byte_t* data, int dataNum) = 0;
    virtual bool setFieldVec(fID_t fieldId, const std::vector<byte_t>& FieldVec) = 0;
    virtual const byte_t* field(fID_t fieldId) const = 0;
    virtual const std::vector<byte_t>& fieldVec(fID_t fieldId) const = 0;
};

#endif
