#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;

public:
    Student(int r, string n)
    {
        rollNo = r;
        name = n;
        cout << "Student object created" << endl;
    }
    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};

void runTest(int testNo, int roll, string name)
{
    cout << "===== Test Case " << testNo << " =====" << endl;
    {
        Student s(roll, name);
        s.display();
    }
    cout << endl;
}

int main()
{
    runTest(1, 102, "Bala");
    runTest(2, 103, "Kumar");

    cout << "Program completed successfully." << endl;
    return 0;
}