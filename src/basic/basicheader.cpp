
#include "../../include/basic/basicheader.h"

BasicHeader::BasicHeader()
{

}

BasicHeader::~BasicHeader()
{

}

void BasicHeader::setField(uint_t field_id, const void* field, uint_t size)
{
    m_fields[field_id] = BasicData(field, size);
}

void BasicHeader::field(uint_t field_id, void* field, uint_t size) const
{
    if (!exists(field_id)) {
        throw std::runtime_error(
            "BasicHeader::field(). "
            "There is no valid field for this field_id."
        );
    }

    m_fields.at(field_id).data(field, size);
}

bool BasicHeader::exists(uint_t field_id) const
{
    if (m_fields.find(field_id) == m_fields.end()) {
        return false;
    }

    return true;
}
