#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle (int length, int width); //Constructor
    void displayArea();
private:
    int m_length;
    int m_width;
    int computeArea();
};

#endif
