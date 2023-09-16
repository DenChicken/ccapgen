#ifndef FOLDINGCUD_H
#define FILDINGCUD_H

#include "basictypes.h"

#include <vector>

class HeaderCUD
{
private:
    std::vector<byte_t> m_CUD;

public:
    inline const std::vector<byte_t>& getCUD() const { return m_CUD; }
    inline void setCUD(const std::vector<byte_t>& newCUD) { m_CUD = newCUD; }
    inline void addCUD(const std::vector<byte_t>& newCUD) {
        m_CUD.insert(m_CUD.end(), newCUD.begin(), newCUD.end());
    }
};

#endif
