#include <iostream>
#include <cstdlib>

long factorial(int);

int main(int argc, char * argv[])
{
    int num = atoi(argv[1]);
    std::cout << factorial(num) << std::endl;
    return 0;
}

long factorial(int num)
{
    if (num == 0) {
        return 1;
    }
    else if (num == 1) {
        return num;
    }
    else {
        return num*factorial(num-1);
    }
}
