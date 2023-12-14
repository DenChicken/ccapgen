
#include "../../include/basic/basicdata.h"


BasicData::BasicData(const BasicData &other)
{
    if (other.m_data && other.m_size) {
        if (m_data) {
            delete[] m_data;
        }

        m_size = other.m_size;
        m_data = new byte_t[m_size];
        memcpy(m_data, other.m_data, other.m_size);
    }
}

BasicData::BasicData(const void* data, uint_t size)
{
    if (data && size) {
        this->setData(data, size);
    }
}

BasicData::~BasicData()
{
    delete[] m_data;
    m_data = nullptr;
}

BasicData& BasicData::operator=(const BasicData& other)
{
    if (other.m_data && other.m_size) {
        if (m_data) {
            delete[] m_data;
        }

        m_size = other.m_size;
        m_data = new byte_t[m_size];
        memcpy(m_data, other.m_data, other.m_size);
    }

    return *this;
}

void BasicData::setData(const void* data, uint_t size)
{
    if (!data) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to set invalid data."
        );
    }

    if (size == 0) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to set zero-size data."
        );
    }

    if (m_data) {
        delete[] m_data;
        m_data = nullptr;
    }

    m_size = size;
    m_data = new byte_t[size];

    memcpy(m_data, data, size);
}

void BasicData::data(void* data, uint_t size) const
{
    if (!data) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to set data to invalid pointer."
        );
    }

    if (size == 0) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to get data of zero size."
        );
    }

    if (m_data) {
        memcpy(data, m_data, size);
    }
}
