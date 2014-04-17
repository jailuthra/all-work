#include "student.h"
#include <iostream>

using namespace std;

void Student::input (void) {
    cout << "\n\nRoll No: ";
    cin >> rollno;
    cout << "Name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "MARKS" << endl;
    cout << "Phy: "; cin >> marks[phy];
    cout << "Chem: "; cin >> marks[chem];
    cout << "Math: "; cin >> marks[math];
}

void Student::output (void) {
    cout << "\n\nRoll No: " << rollno << endl;
    cout << "Name: " << name << endl;
    cout << "MARKS" << endl << "Phy: " << marks[phy] << endl
         << "Chem: " << marks[chem] << endl 
         << "Math: " << marks[math];
}

float Student::totalMarks (void) {
    return (marks[phy] + marks[chem] + marks[math]);
}
