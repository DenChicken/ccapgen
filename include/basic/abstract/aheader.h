#ifndef AHEADER_H
#define AHEADER_H

#include "interfaces/iheader.h"
#include "interfaces/idata.h"
#include "basic/headercud.h"

#include <algorithm>
#include <iterator>

/*
  One strange thing is to allow data to be passed between
  classes in the order R->L and not get confused with the '|='.

  You can still use '|=' or override "operatorX" and use 
  parentheses to explicitly specify the order of "operatorX", 
  but it's clearer this way
*/
#ifndef _add
#define _add |=
#endif

class AHeader : public IHeader, public IData
{
public:
    AHeader() = default;
    virtual ~AHeader() = default;

public:
    // Inherited via IData
    virtual bool setBytes(byte_t* data, int num) override;
    virtual void setBytes(const std::vector<byte_t>& bytesVec) override;
    virtual void bytes(byte_t* retData, int num) override;
    virtual void bytes(std::vector<byte_t>& retVec) override;

    // Inherited via IHeader
    virtual bool setField(fID_t fieldId, byte_t* data, int num) override;
    virtual bool setField(fID_t fieldId, const std::vector<byte_t>& fieldVec) override;
    virtual void field(fID_t fieldId, byte_t* retF, int num) const override;
    virtual void field(fID_t fieldId, std::vector<byte_t>& retFVec) const override;

    // Operator '_add' (aka |=) to add classes in the order R->L 
    AHeader& operator _add(AHeader& hdr);

private:
    /**
    * @brief Fills the header with default fields.
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
    virtual void convertFieldsToBytesVec() = 0;

private:
    // Required to transfer a copy of the data when composing the package
    HeaderCUD m_CUD;

    // Update the CUD for the current header
    void generateCUD();
};

#endif
