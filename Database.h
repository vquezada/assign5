#include "Tree.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <sstream>
#include <algorithm>
using namespace std;

class Database
{
public:
  Database();
  ~Database();
  //for tree
  Tree<Student>* masterStudent ;
  Tree<Faculty>* masterFaculty;
  void infoToFile();
  void dbOptionsOut();
};
