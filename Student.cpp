#include "Student.h"

Student::Student()
{
}
Student::Student(int stuID)
{
  this->stuID = stuID;
}
Student::Student(string name, string year, string major, double gpa, int stuID, int fID)
{
  this->name = name;
  this->year = year;
  this->major = major;
  this->gpa = gpa;
  this->stuID = stuID;
  this->facID = facID;
}
Student::~Student()
{
}
bool operator<(const Student &s1, const Student &s2)
{
  return s1.stuID < s2.stuID;
}
bool operator>(const Student &s1, const Student &s2)
{
  return s1.stuID > s2.stuID;
}
bool operator==(const Student &s1, const Student &s2)
{
  return s1.stuID == s2.stuID;
}
bool operator!=(const Student &s1, const Student &s2)
{
  return s1.stuID != s2.stuID;
}
ostream& operator<<(ostream& out, const Student &s1)
{
    cout << "Name: " << s1.name << endl;
    cout << "Year: " << s1.year << endl;
    cout << "Major: " << s1.major << endl;
    cout << "GPA: " << s1.gpa << endl;
    cout << "Student ID: " << s1.stuID << endl;
    cout << "Advisor ID: " << s1.facID << endl;
  return out;
}
