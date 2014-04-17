#include "student.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

void writeFile(char * fileName);
void readFile(char * fileName);

int main(int argc, char * argv[])
{
    char * fileName = argv[1];
    if (!argv[1]) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 0;
    }
    cout << "WRITING FILE" << endl << endl;
    writeFile(fileName);
    cout << endl << "READING FILE" << endl;
    readFile(fileName);
    return 0;
}

void writeFile(char * fileName)
{
    Student stu;
    char ch = 'y';
    int rollNo;
    float marks;
    char name[25];
    ofstream fout(fileName, ios::out|ios::binary);
    while (ch == 'y') {
        cout << "Name: ";
        cin.getline(name, 25);
        cout << "Roll No.: ";
        cin >> rollNo;
        cout << "Marks: ";
        cin >> marks;
        stu.input(name, rollNo, marks);
        fout.write((char *) &stu, sizeof(stu));
        cout << endl << "Record Written!";
        cout << endl << "Enter another? (y/n): ";
        cin >> ch;
        cin.ignore();
        cout << endl;
    }
    fout.close();
}

void readFile(char * fileName)
{
    Student stu;
    ifstream fin(fileName, ios::out|ios::binary);
    assert(fin);
    while (fin.read((char*) &stu, sizeof(stu))) {
        cout << endl << "Name: " << stu.getName()
             << endl << "Roll No.: " << stu.getRollNo()
             << endl << "Marks: " << stu.getMarks()
             << endl;
    }
    fin.close();
}
