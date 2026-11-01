#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;
};

void runTest(int testNo, string n1, int m1, string n2, int m2,
             string n3, int m3, string n4, int m4)
{
    cout << "===== Test Case " << testNo << " =====" << endl;

    vector<Student> students = {
        {n1, m1, ' '},
        {n2, m2, ' '},
        {n3, m3, ' '},
        {n4, m4, ' '}
    };

    sort(students.begin(), students.end(),
         [](Student a, Student b)
         {
             return a.mark > b.mark;
         });

    transform(students.begin(), students.end(),
              students.begin(),
              [](Student s)
              {
                  if (s.mark >= 90)
                      s.grade = 'A';
                  else if (s.mark >= 75)
                      s.grade = 'B';
                  else if (s.mark >= 50)
                      s.grade = 'C';
                  else
                      s.grade = 'F';
                  return s;
              });

    auto it = find_if(students.begin(), students.end(),
                      [](Student s)
                      {
                          return s.mark > 80;
                      });

    int total = accumulate(students.begin(), students.end(), 0,
                           [](int sum, Student s)
                           {
                               return sum + s.mark;
                           });

    float average = (float)total / students.size();

    cout << "Student Grade Analyzer" << endl;
    cout << "---------------------" << endl;
    cout << "Name\tMark\tGrade" << endl;

    for (Student s : students)
    {
        cout << s.name << "\t" << s.mark << "\t" << s.grade << endl;
    }

    if (it != students.end())
    {
        cout << "\nFirst student scoring above 80: " << it->name << endl;
    }

    cout << "Total Marks: " << total << endl;
    cout << "Average Mark: " << average << endl;
    cout << endl;
}

int main()
{
    runTest(1, "Anu", 95, "Deepa", 78, "Meena", 60, "Siva", 45);
    runTest(2, "Pooja", 92, "Katha", 88, "Mani", 70, "Hari", 55);

    cout << "Program completed successfully." << endl;
    return 0;
}