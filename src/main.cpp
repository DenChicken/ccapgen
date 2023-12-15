#include <iostream>
#include <cassert>

#include "include/basic/basicbitdata.h"
#include "include/basic/basicheader.h"

int main()
{
    uint8_t* data = new uint8_t[1];
    memset(data, 0xFF, 1);
    uint_t data_bits = 2;
    BasicBitData bit_data(data, data_bits);

    return EXIT_SUCCESS;
}
