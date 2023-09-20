#include <iostream>

#include "layers/l3/ipv4.h"

int main()
{
    std::vector<byte_t> data1;
    data1 = { 1, 2, 3, 4 };
    IPv4 a(data1);

    std::vector<byte_t> data2;
    data2 = { 5, 6, 7, 8 };
    IPv4 b(data2);

    a + b;

    return 0;
}
