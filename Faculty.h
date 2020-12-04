#include <string>
#include <iostream>
using namespace std;

class Faculty
{
public:
  //shared variables
  Faculty();
  Faculty(int facID);
  Faculty(string name, string level, string department, int facID);
  ~Faculty();
//faculty attributes
  string name;
  string level;
  string department;
  int facID;
};

bool operator<(const Faculty &f1, const Faculty &f2);
bool operator>(const Faculty &f1, const Faculty &f2);
bool operator==(const Faculty &f1, const Faculty &f2);
bool operator!=(const Faculty &f1, const Faculty &f2);
ostream& operator<<(ostream& out, const Faculty &f1);
