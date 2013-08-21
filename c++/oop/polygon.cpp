#include <iostream>

class Polygon {
    protected:
        int width, height;
    public:
        explicit Polygon (int a, int b)
        { 
            width = a; 
            height = b; 
        }
};

class Rectangle : public Polygon {
    public:
        explicit Rectangle (int a, int b) : Polygon (a, b) {};  // Inherit the constructor
        int area ()
        { 
            return width*height; 
        }
};

class Triangle : public Polygon {
    public:
        explicit Triangle (int a, int b) : Polygon (a, b) {};  // Inherit the constructor
        int area ()
        { 
            return (width*height)/2; 
        }
};

int main() {
    Rectangle rect(4, 8);
    Triangle trgl(4, 8);
    std::cout << "The area of rect is: " << rect.area() << std::endl;
    std::cout << "The area of trgl is: " << trgl.area() << std::endl;
    return 0;
}

          
