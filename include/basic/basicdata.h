#ifndef BASICDATA_H
#define BASICDATA_H

#include "./interfaces/idata.h">

class BasicData : public IData
{
public:
    BasicData() = default;
    BasicData(const BasicData &other);
    BasicData(const void *data, uint_t size);

    virtual ~BasicData();

    BasicData& operator=(const BasicData& other);

public:
    void setData(const void* data, uint_t size) override;
    void data(void* data, uint_t size) const override;

    uint_t inline size() const { return m_size; }

private:
    byte_t* m_data = nullptr;
    uint_t m_size = 0;
};


#endif // BASICDATA_H
