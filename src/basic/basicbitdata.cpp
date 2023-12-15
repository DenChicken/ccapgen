
#include "../../include/basic/basicbitdata.h"


BasicBitData::BasicBitData(const void* data, uint_t bits)
{
    if (data && bits) {
        this->setData(data, bits);
    }
}

BasicBitData::~BasicBitData()
{
    delete[] m_data;
    m_data = nullptr;
    delete[] m_mask;
    m_mask = nullptr;
}

BasicBitData& BasicBitData::operator=(const BasicBitData& other)
{
    if (other.m_data && other.m_mask && other.m_bits && other.m_bytes) {
        if (m_data) {
            delete[] m_data;
        }
        if (m_mask) {
            delete[] m_mask;
        }

        m_bits = other.m_bits;
        m_bytes = other.m_bytes;

        m_data = new byte_t[m_bytes];
        memcpy(m_data, other.m_data, m_bytes);

        m_mask = new byte_t[m_bytes];
        memcpy(m_mask, other.m_mask, m_bytes);
    }
    else {
        fprintf(stderr, "Attempt to copy invalid data");
    }

    return *this;
}

void BasicBitData::setData(const void* data, uint_t bits)
{
    if (!data) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to set invalid data."
        );
    }

    if (bits == 0) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to set zero-bits data."
        );
    }

    m_bits = bits;

    uint_t remaining_bits = 0;
    m_bytes = m_bits / 8;
    if (m_bytes > 0) {
        if (m_bits % 8) {
            remaining_bits = m_bits - m_bytes * 8;
            ++m_bytes;
        }
    } else {
        m_bytes = 1;
        remaining_bits = m_bits;
    }

    if (m_data) {
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = new byte_t[m_bytes];
    memcpy(m_data, data, m_bytes);

    if (m_mask) {
        delete[] m_mask;
        m_mask = nullptr;
    }
    m_mask = new byte_t[m_bytes];
    memset(m_mask, 0xFF, m_bytes);

    if (remaining_bits > 0) {
        byte_t last_mask_value = 0;
        for (uint_t count = 0; count < remaining_bits; ++count) {
            last_mask_value <<= 1;
            last_mask_value |= 1;
        }

        m_mask[m_bytes - 1] = last_mask_value;
    }
}

void BasicBitData::data(void* data) const
{
    if (!data) {
        throw std::runtime_error(
            "Error in BasicData::setData(). "
            "Attempt to set data to invalid pointer."
        );
    }

    if (m_data && m_mask) {
        uint8_t* data_bytes = reinterpret_cast<uint8_t*>(data);

        for (uint_t count = 0; count < m_bytes; ++count) {

            uint8_t byte_under_mask = m_data[count] & m_mask[count];
            memcpy(&data_bytes[count], &byte_under_mask, 1);
        }
    }
}
