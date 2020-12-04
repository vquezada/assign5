#include "Faculty.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <iostream>
Faculty::Faculty()
{
}
Faculty::Faculty(int facID)
{
  this->facID = facID;
}

Faculty::Faculty(string name, string level, string department, int facID)
{
  this->name = name;
  this->level = level;
  this->department = department;
  this->facID = facID;
}

Faculty::~Faculty()
{
}
bool operator<(const Faculty &f1, const Faculty &f2)
{
  return f1.facID < f2.facID;
}
bool operator>(const Faculty &f1, const Faculty &f2)
{
  return f1.facID > f2.facID;
}
bool operator==(const Faculty &f1, const Faculty &f2)
{
  return f1.facID == f2.facID;
}
bool operator!=(const Faculty &f1, const Faculty &f2)
{
  return f1.facID != f2.facID;
}
ostream& operator<<(ostream& out, const Faculty &f1)
{
  std::stringstream result;

  cout << "Name: " << f1.name << endl;
  cout << "Level: " << f1.level << endl;
  cout << "Department: " << f1.department << endl;
  cout << "Faculty ID: " << f1.facID << endl;
  cout << "Advisees' IDs: " << result.str() << endl;

  return out;
}
