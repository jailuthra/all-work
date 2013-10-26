#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle (int length, int width) :
    m_length(length), m_width(width) {}

void Rectangle::displayArea()
{   
    int area = computeArea();
    std::cout << "The area is: " << area << std::endl;
}

int Rectangle::computeArea()
{
    return m_length * m_width;
}
