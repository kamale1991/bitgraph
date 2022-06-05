#include <iostream>
#include <string>

#include "automaton/include/binary_image.h"

int main()
{
    std::cout << "Hello" << std::endl;
    BI::Bitmap *bitmap = new BI::Bitmap;
    std::string filename = "./opencv_sample/home.jpg";
    bitmap->import_image(filename);
}