#ifndef BASICDATA_H
#define BASICDATA_H

#include "./interfaces/ibitdata.h"

class BasicBitData : public IBitData
{
public:
    BasicBitData() = default;
    BasicBitData(const void *data, uint_t bits);

    virtual ~BasicBitData();

    BasicBitData& operator=(const BasicBitData& other);

public:
    virtual void setData(const void* data, uint_t bits) override;
    virtual void data(void* data) const override;

    virtual uint_t inline bitsNum() const override { return m_bits; }
    virtual uint_t inline bytesNum() const override { return m_bytes; }

private:

private:
    byte_t* m_data = nullptr;
    byte_t* m_mask = nullptr;

    uint_t  m_bits  = 0;
    uint_t  m_bytes = 0;
};


#endif // BASICDATA_H
