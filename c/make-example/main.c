#include "hello.h"

int main (int argc, char * argv[]) {
    char *name;
    name = argv[1]? argv[1] : "World";
    hello(name);
    return 0;
}
