#include "basic/abstract/aheader.h"

bool AHeader::setBytes(byte_t* data, int num) 
{
    if (data == nullptr) {
        return false;
    }
    memcpy(&m_bytes[0], data, num * sizeof(byte_t));
    return true;
}

void AHeader::setBytesVec(const std::vector<byte_t>& bytesVec) 
{
    m_bytes = bytesVec;
}

const byte_t* AHeader::getBytes() 
{
    if (m_fields.empty()) {
        if (m_bytes.empty()) {
            return nullptr;
        }
        else {
            return m_bytes.data();
        }
    }
    else {
        return convertFieldsToBytesArray().data();
    }

    return m_bytes.data();
}

const std::vector<byte_t>& AHeader::getBytesVec() const 
{
    return m_bytes;
}

