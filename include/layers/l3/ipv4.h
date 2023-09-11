#ifndef IPv4_H
#define IPv4_H

#include "basic/abstract/interfaces/iheader.h"
#include "basic/sharedsum.h"

class IPv4 : public IHeader, public SharedSum
{
public:
    virtual bool setField(uint8_t pos, byte_t* data) override {
        return true;
    }
    virtual bool setFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec) override {
        return true;
    }
    virtual const byte_t* getBytes() const override {
        return nullptr;
    }
    virtual const std::vector<byte_t>& getBytesVec() const override {
        return std::vector<byte_t>();
    }
    virtual bool insertField(uint8_t pos, byte_t* data) override {
        return true;
    }
    virtual bool insertFieldVec(uint8_t pos, const std::vector<byte_t> FieldVec) override {
        return true;
    }
    virtual bool appendField(byte_t* data) override {
        return true;
    }
    virtual bool appendFieldVec(byte_t* data) override {
        return true;
    }
};

#endif