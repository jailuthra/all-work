#include<iostream>

using namespace std;

int main() {
  int a = 34;
  int* pa = &a;
  cout << "The address for variable \"a\" is: " << pa << endl;
  return 0;
}
