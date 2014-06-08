/* A small utilty to find the number of occurences of a particular word
   in the given file (case-insensitive) */

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int countWord(char *, char *);
bool wordFound(char *, char *, int &);

int main(int argc, char * argv[]) {
    // Check if all arguments are given
    if (!(argv[1] && argv[2])) {
        cout << "Usage: " << argv[0] << " <word_to_count> <filename>" << endl;
        return 1;
    }
    ifstream file;
    file.open(argv[2], ios::in);
    char str[300];
    int count = 0;
    // Read file line-by-line until EOF
    while (!file.eof()) {
        file.getline(str, 300);
        count += countWord(argv[1], str);
    }
    file.close();
    cout << count << endl;
    return 0;
}

/* Counts the number of occurences of word in str */
int countWord(char * word, char * str) {
    int i = 0, j = 0, count = 0;
    // Check if the first word matches
    if (wordFound(word, str, i)) {
        count++;
    }
    // Check the remaining words
    while (str[i]) {
        if (str[i]==' ') {
            i += 1;
            if (wordFound(word, str, i)) {
                count++;
            }
        } else {
            i++;
        }
    }
    return count;
}

/** Checks if subStr is present in the str starting from str[index]
  * Then check if subStr is followed with a blank space, comma, null etc.
  * which means it is a word */
bool wordFound(char * subStr, char * str, int &index) {
    bool substrFound = true;
    int j = 0;
    while (subStr[j]) {
        if (tolower(subStr[j]) != tolower(str[index])) {
            substrFound = false;
            break;
        } else {
            index++;
            j++;
        }
    }
    bool substrIsWord;
    switch (str[index]) {
    case ' ': case ';': case '.':
    case ':': case ',': case '\0':
        substrIsWord = true;
        break;
    default:
        substrIsWord = false;
        break;
    }
    return substrFound && substrIsWord;
}

