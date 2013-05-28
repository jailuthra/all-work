#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char * argv[]) {
    
    int n, i=3, result=0;
    n = atoi(argv[1]);

    if (n==2 || n==3) result=1;    // Check if the number is 2 or 3
    else if (n%2 == 0) result=0;    // Check if number is even
    else {
        // Check if n is divisible by odd numbers
        while (n%i != 0) {
            i += 2;
            if (i>(n/2)) {
                result = 1;
                break;
            }
        }
    }

    if (result) cout<<"prime"<<endl;
    else cout<<"not prime"<<endl;
    
    return 0;
}
