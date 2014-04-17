#include "student.h"
#include <iostream>

using namespace std;

int main (void) {
    int n, i, rollno, found=0;
    cout << "Enter no. of students: ";
    cin >> n;
    Student std[10];
    cout << "\nSTUDENT DATABASE ENTRY";
    for (i=0; i<n; i++) {
        cout << "\n\nStudent " << i+1;
        std[i].input();
    }
    cout << "\n\nEnter the roll no to search for: ";
    cin >> rollno;
    for (i=0; i<n; i++) {
        if (std[i].rno() == rollno) {
            std[i].output();
            found = 1;
        }
    }
    if (!found)
        cout << "Student not found!";
    float marks;
    cout << "\n\nEnter the minimum total marks: ";
    cin >> marks;
    for (i=0; i<n; i++) {
        if (std[i].totalMarks() > marks)
            std[i].output();
    }
    return 0;
}

