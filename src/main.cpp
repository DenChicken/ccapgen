#include <iostream>
#include <cassert>

#include "include/basic/basicdata.h"
#include "include/basic/basicheader.h"

int main()
{
    BasicData data;

    struct test
    {
        byte_t field1 = 0;
        byte_t field2 = 0;
        byte_t field3 = 0;
    };

    test S{ 1, 2, 3 };

    data.setData(&S, sizeof(S));

    test S1;
    data.data(&S1, sizeof(S1));

    assert(memcmp(&S, &S1, sizeof(S)) == 0);

    try
    {
        data.setData(&S1, 0);
    }
    catch (const std::runtime_error &ex)
    {
        std::cout << "Hello\n" << ex.what();
    }

    BasicHeader header;
    header.setField<test>(0, S1);

    test S3;
    header.field<test>(0, S3);

    return 0;
}
