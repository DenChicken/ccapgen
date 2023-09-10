#include "basic/interfaces/iheader.h"
#include "basic/basedata.h"
#include "basic/abstract/asummand.h"

class AHeader : public IHeader, public BaseData, public ASummand
{
public:
    AHeader() = default;
    virtual ~AHeader() = default;

    virtual bool setField(const int fieldId, const void* fieldValue) override = 0;
    virtual bool field(const int fieldId) const override = 0;
};