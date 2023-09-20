#ifndef AHEADER_H
#define AHEADER_H

#include "interfaces/iheader.h"
#include "interfaces/idata.h"

class AHeader : public IHeader, public IData
{
public:
    AHeader() = default;
    virtual ~AHeader() = default;

public:
    // Inherited via IData
    virtual bool setBytes(byte_t* data, int num) override;
    virtual void setBytesVec(const std::vector<byte_t>& bytesVec) override;
    virtual const byte_t* getBytes() override;
    virtual const std::vector<byte_t>& getBytesVec() const override;

    // Inherited via IHeader
    virtual bool setField(fID_t fieldId, byte_t* data, int dataNum) override;
    virtual bool setFieldVec(fID_t fieldId, const std::vector<byte_t>& fieldVec) override;
    virtual const byte_t* field(fID_t fieldId) const override;
    virtual const std::vector<byte_t>& fieldVec(fID_t fieldId) const override;

private:
    /**
    * @brief Fills in the header fields with default values.
    * This function MUST be called in the constructor of the overridden class 
    */
    virtual void setDefaultFields() = 0;

    /**
    * @brief Processing a specific field by its ID
    * @param fieldId - ID of the header field
    */
    virtual void fieldProcessing(fID_t fieldId) = 0;

    /**
    * @brief Converts header fields to a vector of bytes
    */
    virtual const std::vector<byte_t>& convertFieldsToBytesVec() = 0;
};

#endif
