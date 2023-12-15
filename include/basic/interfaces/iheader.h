#ifndef IHEADER_H
#define IHEADER_H

#include "basic/basictypes.h"

class IHeader
{
public:
    virtual void setField(uint_t field_id, const void* field) = 0;
    virtual void field(uint_t field_id, void* field) const = 0;
    virtual bool isFieldExists(uint_t field_id) const = 0;
    virtual uint_t fieldLen(uint_t field_id) const = 0;
};

#endif
