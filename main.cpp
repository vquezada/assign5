#include "Database.h"
#include <iostream>
#include <fstream>
#include <cstddef>
using namespace std;
int main (int argc, char** argv)
{
  Database dbInfo;
  dbInfo.infoToFile();
  dbInfo.dbOptionsOut();
  cout << "\n" << endl;
  return 0;
}
