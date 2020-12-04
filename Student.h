#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int stuID);
  Student(string name, string year, string major, double gpa, int stuID, int fID);
  ~Student();
//student attributes
  string name;
  string year;
  string major;
  double gpa;
  int stuID;
  int facID;
};
ostream& operator<<(ostream& out, const Student &s1);
bool operator<(const Student &s1, const Student &s2);
bool operator>(const Student &s1, const Student &s2);
bool operator==(const Student &s1, const Student &s2);
bool operator!=(const Student &s1, const Student &s2);
