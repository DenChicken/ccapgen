#include "basic/types/basictypes.h"

#include "idata.h"

class IHeader : public IData
{

public:
    virtual ~IHeader() = default;

    /**
    * @brief Set the field corresponding to the specified identifier
    * 
    * @param fieldId - field identifier (int)
    * @param fieldValue - field value (void *)
    * @return Returns the result of the action: 'true' - success, 'false' - failure
    **/
    virtual bool setField(const int fieldId, const void* fieldValue) = 0;

    /**
    * @brief Get the field corresponding to the specified identifier
    *
    * @param fieldId - field identifier (int)
    * @return Returns the result of the action: 'true' - success, 'false' - failure
    **/
    virtual bool field(const int fieldId) const = 0;
    
    virtual byte_t* getBytes() const = 0;

    /**
    * @brief Set the header as an array of bytes
    *
    * @return Returns the array of bytes (byte_t)
    **/
    virtual bool setBytes(const byte_t* bytes) = 0;

private:
    virtual bool headerGenPriv() = 0;
};
