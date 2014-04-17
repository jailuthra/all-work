#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    char m_name[25];
    int m_rollNo;
    float m_marks;
public:
    Student(char name[25], int rollNo, float marks);
    Student();
    void input(char name[25], int rollNo, float marks);
    char * getName();
    int getRollNo();
    float getMarks();
};

#endif
