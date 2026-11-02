#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    string department;

public:
    Student(int r, string n, string d)
    {
        rollNo = r;
        name = n;
        department = d;

        cout << "Student object created" << endl;
    }

    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }

    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};

int main()
{
    Student s1(105,"Tina","IT");

    s1.display();

    return 0;
}
