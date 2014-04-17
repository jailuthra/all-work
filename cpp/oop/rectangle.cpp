#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle (int length=0, int width=0) :
    m_length(length), m_width(width) {}

void Rectangle::displayArea()
{   
    std::cout << "The area is: " << computeArea() << std::endl;
}

int Rectangle::computeArea()
{
    return m_length * m_width;
}
