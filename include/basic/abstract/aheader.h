#ifndef AHEADER_H
#define AHEADER_H

#include "interfaces/iheader.h"
#include "interfaces/idata.h"

class AHeader : public IHeader, public IData
{
public:
    // Inherited via IData
    virtual bool setBytes(byte_t* data, int num) override;
    virtual void setBytesVec(const std::vector<byte_t>& bytesVec) override;
    virtual const byte_t* getBytes() override;
    virtual const std::vector<byte_t>& getBytesVec() const override;

    // Inherited via IHeader
    virtual bool setField(uint8_t pos, byte_t* data) = 0;
    virtual bool setFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) = 0;
    virtual bool insertField(uint8_t pos, byte_t* data) = 0;
    virtual bool insertFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) = 0;
    virtual bool appendField(byte_t* data) = 0;
    virtual bool appendFieldVec(byte_t* data) = 0;

private:
    virtual const std::vector<byte_t>& convertFieldsToBytesArray() = 0;
};

#endif
