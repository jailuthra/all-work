/* A small utilty to find the number of occurences of a particular word
   in the given file (case-insensitive) */

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int countWord(char *, ifstream &);
bool wordMatches(char *, ifstream &);

int main(int argc, char * argv[]) {
    // Check if all arguments are given
    if (!(argv[1] && argv[2])) {
        cout << "Usage: " << argv[0] << " <word_to_count> <filename>" << endl;
        return 1;
    }
    ifstream file;
    file.open(argv[2], ios::in);
    int count = countWord(argv[1], file);
    file.close();
    cout << count << endl;
    return 0;
}

int countWord(char * word, ifstream & file) {
    char ch;
    int count = 0;
    // Check if the first word in the file matches
    if (wordMatches(word, file)) {
        count++;
    }
    // Check the remaining words
    while (file.get(ch)) {
        if (ch == ' ' || ch == '\n') {
            if (wordMatches(word, file)) {
                count++;
            }
        }
    }
    return count;
}

bool wordMatches(char * word, ifstream & file) {
    int j = 0;
    char ch;
    while (word[j]) {
        file.get(ch);
        if (tolower(word[j]) != tolower(ch)) {
            return false;
        } else {
            j++;
        }
    }
    // Check if the word has ended in the stream w/o modifying the stream
    switch (file.peek()) {
        case ' ': case ';': case '.':
        case ':': case ',': case '\n':
            return true;
        default:
            return false;
    }
}
