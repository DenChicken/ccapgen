#include "basic/types/basictypes.h"

class IData
{
protected:
    byte_t* m_bytes = nullptr;

public:
    virtual ~IData() { delete[] m_bytes; }

    /**
    * @brief Get the header as an array of bytes
    *
    * @return Returns the array of bytes (byte_t)
    **/
    virtual byte_t* getBytes() const = 0;

    /**
    * @brief Set the header as an array of bytes
    *
    * @return Returns the array of bytes (byte_t)
    **/
    virtual bool setBytes(const byte_t* bytes) = 0;
};
