#include "layers/l3/ipv4.h"

IPv4::IPv4(std::vector<byte_t> CUD)
{
    m_bytes = CUD;
}

void IPv4::setDefaultFields()
{

}

void IPv4::fieldProcessing(fID_t fieldId)
{

}

void IPv4::convertFieldsToBytesVec()
{
    if (m_fields.empty())
    {
        return;
    }

    std::map<fID_t, std::vector<byte_t>>::iterator it;
    for (it = m_fields.begin(); it != m_fields.end(); ++it)
    {
        m_bytes.insert(m_bytes.end(), it->second.begin(), it->second.end());
    }
}
