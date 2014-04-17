#ifndef STUDENT
#define STUDENT

class Student
{
    int rollno;
    char name[20];
    float marks[3];
    enum { phy=0, chem, math };
public:
    void input(void);
    void output(void);
    int rno(void) { return rollno; }
    float totalMarks(void);
};

#endif
