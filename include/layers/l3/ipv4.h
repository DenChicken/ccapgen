#ifndef IPv4_H
#define IPv4_H

#include "basic/abstract/aheader.h"

class IPv4 : public AHeader
{
public:


private:
    // Inherited via AHeader
    void setDefaultFields() override;
    void fieldProcessing(fID_t fieldId) override;
    const std::vector<byte_t>& convertFieldsToBytesVec() override;
};

#endif
