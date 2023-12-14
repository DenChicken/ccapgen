#ifndef BASICHEADER_H
#define BASICHEADER_H

#include "basicdata.h"
#include "interfaces/iheader.h"

#include <unordered_map>

class BasicHeader : public IHeader
{
public:
    BasicHeader();
    virtual ~BasicHeader();

public:
    virtual void setField(uint_t field_id, const void* field, uint_t size) override;
    virtual void field(uint_t field_id, void* field, uint_t size) const override;

public:
    bool exists(uint_t field_id) const;

    template <class T>
    void setField(uint_t field_id, const T field);

    template <class T>
    T field(uint_t field_id);

    template <class T>
    void field(uint_t field_id, T &field);

private:
    std::unordered_map<uint_t, BasicData> m_fields;
};


template<class T>
inline void BasicHeader::setField(uint_t field_id, const T field)
{
    this->setField(field_id, &field, sizeof(T));
}

template<class T>
inline T BasicHeader::field(uint_t field_id)
{
    T ret;
    this->field(field_id, &ret, sizeof(T));

    return ret;
}

template<class T>
inline void BasicHeader::field(uint_t field_id, T& field)
{
    this->field(field_id, &field, sizeof(T));
}

#endif // BASICHEADER_H
