/**
 * @file binary_image.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "include/binary_image.h"

namespace BI
{
    void Bitmap::show_head()
    {
        std::cout << "(width,height,ch) = (" << this->width << "," << this->height << "," << this->ch << std::endl;
    }

    void Bitmap::show_data()
    {
        int index = 0;
        for (int iy = 0; iy < height; iy++)
        {
            for (int ix = 0; ix < width; ix++)
            {
                for (int ic = 0; ic < ch; ic++)
                {
                    std::cout << data[ic + ix * ch] << " ";
                }
                if (ix != width - 1)
                {
                    std::cout << ", ";
                }
            }
            if (iy != height - 1)
            {
                std::cout << std::endl;
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, const BytePixels &bp)
    {
        os << std::bitset<8>(bp.byte);
        return os;
    }

    void Bitmap::import_image(std::string filename)
    {
        cv::Mat original_image;
        original_image = cv::imread(filename);
        this->width = original_image.size().width;
        this->height = original_image.size().height;
        this->ch = original_image.channels();
        this->data = original_image.data;
    };
};