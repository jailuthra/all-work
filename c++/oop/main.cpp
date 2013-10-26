#include "rectangle.h"
#include <iostream>

using namespace std;

int main()
{
    int length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;       
    Rectangle rect(length, width);
    rect.displayArea();
    return 0;
}
