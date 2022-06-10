/**
 * @file binary_image.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "gtest/gtest.h"
#include "../srcs/automaton/include/binary_image.h"

namespace BI
{
    TEST(BytePixels, set)
    {
        BytePixels ebpix;
        ebpix.set(0, 1);
        int8_t i = 0b00000001;
        BytePixels golden = BytePixels(i);
        EXPECT_EQ(true, ebpix == golden);

        ebpix.set(7, 1);
        i = 0b10000001;
        golden = BytePixels(i);
        EXPECT_EQ(true, ebpix == golden);

        ebpix.set(7, 0);
        EXPECT_EQ(true, ebpix == BytePixels(0b00000001));

        ebpix.set(0, 0);
        EXPECT_EQ(true, ebpix == BytePixels(0b00000000));

        ebpix.one();
        EXPECT_EQ(true, ebpix == BytePixels(0b11111111));

        ebpix.zero();
        EXPECT_EQ(true, ebpix == BytePixels(0b00000000));
    };

    TEST(BinaryMap, dump)
    {
        int16_t w = 4;
        int16_t h = 6;
        int16_t comp_type = 0;
        int16_t size = 0;
        BinaryMapHeader *header = new BinaryMapHeader(w, h, comp_type, size);

        size_t nbyte = std::ceil(w * h * 0.125);
        BytePixels **data = new BytePixels *[nbyte];
        for (int i = 0; i < nbyte; i++)
        {
            data[i] = new BytePixels();
        }
        BinaryMap *bim = new BinaryMap(header, data);

        std::string filename = "./sample/test.bim";
        bim->dump(filename);
    };

    TEST(BinaryMap, constructor_int8_array)
    {
        int16_t w = 3;
        int16_t h = 5;
        int8_t *data = new int8_t[15];
        for (int i = 0; i < 15; i++)
        {
            if (i % 3 == 0)
            {
                data[i] = 1;
            }
            else
            {
                data[i] = 0;
            }
        }
        std::cout << data[0] << std::endl;
        BinaryMap *bim = new BinaryMap(w, h, data);
        bim->show_head();
        bim->show_data();
    };

    TEST(read_binary_map, test_bim)
    {
        std::string filename = "./sample/test.bim";
        BinaryMap *new_bim = new BinaryMap;
        read_binary_map(filename, new_bim);

        BinaryMapHeader *golden = new BinaryMapHeader(4, 6, 0, 0);
        EXPECT_EQ(*(new_bim->header_) == *golden, true);
        for (int i = 0; i < new_bim->number_of_byte(); i++)
        {
            EXPECT_EQ(new_bim->data_[i]->byte, 0);
        }
    };
};