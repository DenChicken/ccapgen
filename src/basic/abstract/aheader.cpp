#include "basic/abstract/aheader.h"


bool AHeader::setBytes(byte_t* data, int num)
{
    if (data == nullptr) 
    {
        return false;
    }

    m_bytes.clear();
    m_bytes.resize(num);
    memcpy(m_bytes.data(), data, num * sizeof(byte_t));

    return true;
}

void AHeader::setBytesVec(const std::vector<byte_t>& bytesVec) 
{
    m_bytes = bytesVec;
}

const byte_t* AHeader::getBytes() 
{
    if (m_fields.empty()) 
    {
        if (m_bytes.empty()) 
        {
            return nullptr;
        }
        else 
        {
            return m_bytes.data();
        }
    }
    else 
    {
        this->convertFieldsToBytesVec();
    }

    return m_bytes.data();
}

const std::vector<byte_t>& AHeader::getBytesVec() const 
{
    return m_bytes;
}

bool AHeader::setField(fID_t fieldId, byte_t* data, int dataNum)
{
    if (data == nullptr || m_fields.find(fieldId) == m_fields.end())
    {
        return false;
    }
    
    m_fields[fieldId].clear();
    m_fields[fieldId].resize(dataNum);
    memcpy(m_fields[fieldId].data(), data, dataNum * sizeof(byte_t));

    this->fieldProcessing(fieldId);

    return true;
}

bool AHeader::setFieldVec(fID_t fieldId, const std::vector<byte_t>& fieldVec)
{
    if (fieldVec.empty() || m_fields.find(fieldId) == m_fields.end())
    {
        return false;
    }

    this->fieldProcessing(fieldId);

    m_fields[fieldId] = fieldVec;

    return true;
}

const byte_t* AHeader::field(fID_t fieldId) const
{
    if (m_fields.find(fieldId) == m_fields.end())
    {
        return nullptr;
    }

    return m_fields.at(fieldId).data();
}

const std::vector<byte_t>& AHeader::fieldVec(fID_t fieldId) const
{
    if (m_fields.find(fieldId) == m_fields.end())
    {
        return std::vector<byte_t>();
    }

    return m_fields.at(fieldId);
}

AHeader& AHeader::operator _op(AHeader& hdr)
{
    if (hdr.m_CUD.getCUD().size() == 0) {
        hdr.generateCUD();
    }
    this->generateCUD();

    m_CUD.addCUD(hdr.m_CUD.getCUD());

    return *this;
}

void AHeader::generateCUD()
{
    if (!m_fields.empty())
    {
        this->convertFieldsToBytesVec();
    }

    m_CUD.setCUD(m_bytes);
}


