
#include "../../include/basic/basicheader.h"

#include <utility>

BasicHeader::BasicHeader()
{

}

BasicHeader::~BasicHeader()
{

}

void BasicHeader::setField(uint_t field_id, const void* field)
{
    if (!isFieldExists(field_id)) {
        throw std::runtime_error(
            "BasicHeader::field(). "
            "There is no valid field for this field_id."
        );
    }

    uint_t field_bits = m_fields.at(field_id).bitsNum();

    m_fields.at(field_id).setData(field, field_bits);
}

void BasicHeader::field(uint_t field_id, void* field) const
{
    if (!isFieldExists(field_id)) {
        throw std::runtime_error(
            "BasicHeader::field(). "
            "There is no valid field for this field_id."
        );
    }

    m_fields.at(field_id).data(field);
}

bool BasicHeader::isFieldExists(uint_t field_id) const
{
    if (m_fields.find(field_id) == m_fields.end()) {
        return false;
    }

    return true;
}

uint_t BasicHeader::fieldLen(uint_t field_id) const
{
    if (!isFieldExists(field_id)) {
        throw std::runtime_error(
            "BasicHeader::field(). "
            "There is no valid field for this field_id."
        );
    }

    return m_fields.at(field_id).bitsNum();
}
