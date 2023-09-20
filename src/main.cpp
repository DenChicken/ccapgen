#include <iostream>

#include "layers/l3/ipv4.h"

int main()
{
    std::vector<byte_t> data1 { 1, 1, 1, 1 };
    IPv4 a(data1);

    std::vector<byte_t> data2 { 2, 2, 2 };
    IPv4 b(data2);

    std::vector<byte_t> data3 { 3, 3, 3, 3, 3, 3 };
    a _op b _op IPv4(data3) _op IPv4(std::vector<byte_t> { 9, 9, 9} );

    return 0;
}
