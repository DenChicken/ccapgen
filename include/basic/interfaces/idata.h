#include <vector>

#include "basic/basictypes.h"

class IData
{
protected:
    std::vector<byte_t> m_dataArr;

public:
    virtual ~IData() { }

    /**
    * @brief Get the header as an array of bytes
    *
    * @return Returns the array of bytes (byte_t)
    **/
    virtual const byte_t* getBytes() const = 0;

    /**
    * @brief Set the header as an array of bytes
    *
    * @return Returns the array of bytes (byte_t)
    **/
    virtual bool setBytes(const byte_t* bytes, int num) = 0;
};
