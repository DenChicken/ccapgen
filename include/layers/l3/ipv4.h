#include "basic/interfaces/iheader.h"

class IPv4 : public IHeader
{
public:
    IPv4() = default;
    virtual ~IPv4();

    virtual bool setField(const int fieldId, const void* fieldValue) override;
    virtual bool field(const int fieldId) const override;
    virtual byte_t *getBytes() const override;
    virtual bool setBytes(const byte_t* bytes) override;

private:
    virtual bool headerGenPriv() override;
};
