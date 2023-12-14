#ifndef IPACKET_H
#define IPACKET_H

#include "iheader.h"

class IPacket
{
public:
    virtual bool setHeader(uint8_t pos, const IHeader& hdr) = 0;
    virtual const IHeader& getHeader(uint8_t pos) const = 0;
    virtual bool insertHeader(uint8_t pos, const IHeader& hdr) = 0;
    virtual bool appendHeader(const IHeader& hdr) = 0;
};

#endif
