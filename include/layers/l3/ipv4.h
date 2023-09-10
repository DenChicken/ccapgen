#include "basic/abstract/aheader.h"

class IPv4 : public AHeader
{
public:
    IPv4() = default;
    virtual ~IPv4() = default;

    virtual bool setField(const int fieldId, const void* fieldValue) override;
    virtual bool field(const int fieldId) const override;

private:
    bool headerGenPriv();
};
