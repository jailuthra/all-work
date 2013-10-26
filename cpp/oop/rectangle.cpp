#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle (int length, int width) :
    m_length(length), m_width(width) {}

void Rectangle::displayArea()
{   
    std::cout << "The area is: " << computeArea() << std::endl;
}

int Rectangle::computeArea()
{
    return m_length * m_width;
}
