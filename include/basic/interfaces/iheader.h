#ifndef IHEADER_H
#define IHEADER_H

#include "basic/basictypes.h"

class IHeader
{
public:
    virtual void setField(uint_t field_id, const void* field, uint_t size) = 0;
    virtual void field(uint_t field_id, void* field, uint_t size) const = 0;
};

#endif
