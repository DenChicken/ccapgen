#ifndef IPACKET_H
#define IPACKET_H

#include "iheader.h"

class IPacket
{
private:
    std::map<uint8_t, IHeader> m_headers;

public:
    virtual bool setHeader(uint8_t pos, const IHeader& hdr) = 0;
    virtual const IHeader& getHeader(uint8_t pos) const = 0;
    virtual bool insertHeader(uint8_t pos, const IHeader& hdr) = 0;
    virtual bool appendHeader(const IHeader& hdr) = 0;
};

#endif IPACKET_H