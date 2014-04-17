#include "student.h"
#include <cstring>

Student::Student(char name[25], int rollNo, float marks) :
  m_rollNo(rollNo), m_marks(marks)
{
    strcpy(m_name, name);
}

Student::Student() : m_rollNo(0), m_marks(0.0)
{
}

void Student::input(char name[25], int rollNo, float marks)
{
    strcpy(m_name, name);
    m_rollNo = rollNo;
    m_marks = marks;
}

char * Student::getName()
{
    return m_name;
}

int Student::getRollNo()
{
    return m_rollNo;
}

float Student::getMarks()
{
    return m_marks;
}
