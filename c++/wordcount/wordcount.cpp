#include <iostream>

using namespace std;

int count_words (char * str);   // Input the address of the first character of the string

int main() {
    const int STRLEN = 100;
    char str[STRLEN];
    cout << "Type a sentence: ";
    cin.getline(str, STRLEN);
    cout << "\nThis sentence contains " << count_words(str) << " words" << endl;
    return 0;
}

int count_words (char * str) {
    int count = 0;
    /* Loop until *str is NULL CHAR (\0) */
    while (*str) {
        if (*str == ' ')   
            count++;
        str++;
    } 
    return (count+1);   // number of words = number of spaces + 1
}
