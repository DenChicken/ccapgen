#ifndef BASICHEADER_H
#define BASICHEADER_H

#include "basicbitdata.h"
#include "interfaces/iheader.h"

#include <unordered_map>

class BasicHeader : public IHeader
{
public:
    BasicHeader();
    virtual ~BasicHeader();

public:
    virtual void setField(uint_t field_id, const void* field) override;
    virtual void field(uint_t field_id, void* field) const override;
    virtual bool isFieldExists(uint_t field_id) const override;
    virtual uint_t fieldLen(uint_t field_id) const override;

public:
    template <class T>
    void setField(uint_t field_id, const T field);

    template <class T>
    T field(uint_t field_id);

    template <class T>
    void field(uint_t field_id, T &field);

private:
    std::unordered_map<uint_t, BasicBitData> m_fields;
};


template<class T>
inline void BasicHeader::setField(uint_t field_id, const T field)
{
    this->setField(field_id, &field);
}

template<class T>
inline T BasicHeader::field(uint_t field_id)
{
    T ret;
    this->field(field_id, &ret, sizeof(T) * 8);

    return ret;
}

template<class T>
inline void BasicHeader::field(uint_t field_id, T& field)
{
    this->field(field_id, &field);
}

#endif // BASICHEADER_H
