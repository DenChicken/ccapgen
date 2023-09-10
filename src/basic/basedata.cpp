#include "basic/basedata.h"

const byte_t* BaseData::getBytes() const
{
    return m_dataArr.data();
}

bool BaseData::setBytes(const byte_t* bytes, int num)
{
    if (bytes == nullptr) {
        return false;
    }

    m_dataArr.clear();
    m_dataArr.resize(num);
    for (int count = 0; count < num; ++count) {
        m_dataArr.push_back(bytes[count]);
    }

    return true;
}
