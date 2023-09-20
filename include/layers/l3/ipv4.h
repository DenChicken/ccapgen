#ifndef IPv4_H
#define IPv4_H

#include "basic/abstract/aheader.h"
#include <iostream>

class IPv4 : public AHeader
{
public:
    IPv4(std::vector<byte_t> CUD);
    virtual ~IPv4() = default;

private:
    // Inherited via AHeader

    void setDefaultFields() override;
    void fieldProcessing(fID_t fieldId) override;
    void convertFieldsToBytesVec() override;
};

#endif
