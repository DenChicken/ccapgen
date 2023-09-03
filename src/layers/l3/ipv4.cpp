#include "layers/l3/ipv4.h"

IPv4::~IPv4()
{
}

bool IPv4::setField(const int fieldId, const void* fieldValue)
{
    return false;
}

bool IPv4::field(const int fieldId) const
{
    return false;
}

byte_t *IPv4::getBytes() const
{
    return m_bytes;
}

bool IPv4::setBytes(const byte_t* bytes)
{
    return false;
}

bool IPv4::headerGenPriv()
{
    return false;
}
