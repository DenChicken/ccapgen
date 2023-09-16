#ifndef IPv4_H
#define IPv4_H

#include "basic/abstract/aheader.h"

class IPv4 : public AHeader
{
public:
    // Inherited via AHeader
    bool setField(uint8_t pos, byte_t* data) override;

    bool setFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) override;

    bool insertField(uint8_t pos, byte_t* data) override;

    bool insertFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) override;

    bool appendField(byte_t* data) override;

    bool appendFieldVec(byte_t* data) override;

    virtual const std::vector<byte_t>& convertFieldsToBytesArray() override;
};

#endif
