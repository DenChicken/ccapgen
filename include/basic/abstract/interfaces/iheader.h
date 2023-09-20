#ifndef IHEADER_H
#define IHEADER_H

#include <vector>
#include <map>

#include "basic/basictypes.h"

class IHeader
{
public:
    typedef uint8_t fID_t;

protected:
    std::map<fID_t, std::vector<byte_t>> m_fields;
    
public:
    /**
    * @brief Set the field for the current header
    * 
    * @param fieldId - field ID
    * @param data - data to be installed (byte array)
    * @param num - the number of bytes to be set
    * 
    * @return Returns 'true' if successful. Otherwise 'false'
    */
    virtual bool setField(fID_t fieldId, byte_t* data, int num) = 0;

    /**
    * @brief Set the field for the current header
    *
    * @param fieldId - field ID
    * @param data - data to be installed (vector)
    *
    * @return Returns 'true' if successful. Otherwise 'false'
    */
    virtual bool setField(fID_t fieldId, const std::vector<byte_t>& fieldVec) = 0;

    /**
    * @brief Get the current header field
    * 
    * @param fieldId - field ID
    * @param retData - pointer to the data to return
    * @param num - the number of bytes to be set
    */
    virtual void field(fID_t fieldId, byte_t *retData, int num) const = 0;

    /**
    * @brief Get the current header field
    *
    * @param fieldId - field ID
    * @param retFVec - vector to which the data will be copied
    */
    virtual void field(fID_t fieldId, std::vector<byte_t>& retFVec) const = 0;
};

#endif
