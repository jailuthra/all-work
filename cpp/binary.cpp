#include<iostream>

using namespace std;

int main() {
    int i, n, num, beg, end, mid, a[100], pos, flag=0;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements in ascending order of magnitude, one by one:\n";
    for (i=0; i<n; i++)
        cin >> a[i];
    beg = 0;
    end = n-1;
    mid = (beg + end)/2;
    cout << "Enter the number to search for: ";
    cin >> num;
    do {
        if (num == a[mid]) {
            pos = mid+1;
            flag = 1;
            break;
        }
        else if (num < a[mid])
            end = mid-1;
        else if (num > a[mid])
            beg = mid+1;
        mid = (beg + end)/2;
    } while (beg != end);
    if (flag == 1)
        cout << "\nThe number was found at position: " << pos << endl;
    else
        cout << "\nThe number was not found in the given array" << endl;
    return 0;
}
