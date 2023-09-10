#include "basic/interfaces/idata.h"

class BaseData : public IData
{
public:
    BaseData() = default;
    virtual ~BaseData() = default;

    virtual const byte_t* getBytes() const override;
    virtual bool setBytes(const byte_t* bytes, int num);
};
