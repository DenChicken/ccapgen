#ifndef SHAREDSUM_H
#define SHAREDSUM_H

#include <memory>

class SharedSum : std::enable_shared_from_this<SharedSum>
{
private:
    std::shared_ptr<SharedSum> m_ptrToThis;
    std::shared_ptr<const SharedSum> m_rightElement;

public:
    inline operator std::shared_ptr<const SharedSum>() const { return shared_from_this(); }
    SharedSum& operator+(const std::shared_ptr<const SharedSum>& hdrShrdPtr) {
        m_rightElement = hdrShrdPtr;

        return *this;
    }
};

#endif
