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

    m_fields.clear();
    this->generateCUD();

    return true;
}

void AHeader::setBytes(const std::vector<byte_t>& bytesVec) 
{
    m_bytes = bytesVec;

    m_fields.clear();
    this->generateCUD();
}

void AHeader::bytes(byte_t* retData, int num)
{
    if (retData == nullptr)
    {
        return;
    }

    this->convertFieldsToBytesVec();
    if (m_bytes.empty())
    {
        retData = nullptr;
        return;
    }

    memcpy(retData, m_bytes.data(), sizeof(byte_t) * num);
}

void AHeader::bytes(std::vector<byte_t>& retVec)
{
    this->convertFieldsToBytesVec();
    if (m_bytes.empty())
    {
        return;
    }

    retVec.clear();

    std::copy(m_bytes.begin(), m_bytes.end(), std::back_inserter(retVec));
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

bool AHeader::setField(fID_t fieldId, const std::vector<byte_t>& fieldVec)
{
    if (fieldVec.empty() || m_fields.find(fieldId) == m_fields.end())
    {
        return false;
    }

    this->fieldProcessing(fieldId);

    m_fields[fieldId] = fieldVec;

    return true;
}

void AHeader::field(fID_t fieldId, byte_t* retF, int num) const
{
    if (retF == nullptr || m_fields.empty() || fieldId >= m_fields.size())
    {
        retF = nullptr;
        return;
    }

    memcpy(retF, m_fields.at(fieldId).data(), sizeof(byte_t) * num);
}

void AHeader::field(fID_t fieldId, std::vector<byte_t>& retFVec) const
{
    if (m_fields.empty() || fieldId >= m_fields.size())
    {
        return;
    }

    retFVec.clear();

    std::copy(m_bytes.begin(), m_bytes.end(), std::back_inserter(retFVec));
}

AHeader& AHeader::operator _add(AHeader& hdr)
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


