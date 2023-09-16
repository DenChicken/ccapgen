#include "layers/l3/ipv4.h"

bool IPv4::setField(uint8_t pos, byte_t* data)
{
    return false;
}

bool IPv4::setFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec)
{
    return false;
}

bool IPv4::insertField(uint8_t pos, byte_t* data)
{
    return false;
}

bool IPv4::insertFieldVec(uint8_t pos, const std::vector<byte_t>& FieldVec)
{
    return false;
}

bool IPv4::appendField(byte_t* data)
{
    return false;
}

bool IPv4::appendFieldVec(byte_t* data)
{
    return false;
}

const std::vector<byte_t>& IPv4::convertFieldsToBytesArray()
{
    return std::vector<byte_t>();
}

