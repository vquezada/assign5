#include "Database.h"
using namespace std;
Database::Database()
{
  masterStudent  = new Tree<Student>;
  masterFaculty = new Tree<Faculty>;
}
Database::~Database()
{
  delete masterStudent ;
  delete masterFaculty;
}
//opens file
void Database::infoToFile()
{
  ifstream fileStu;
  ifstream fileFac;
  fileStu.open("student.txt");
  fileFac.open("faculty.txt");
  string line = "";
  if (fileStu.is_open() && fileStu.good())
  {
    while (!fileStu.eof())
    {
      string n = "";
      string y = "";
      string m = "";
      double g = 0;
      int sID = 0;
      int fID = 0;

      getline(fileStu, line);
      if (line.empty())
        continue;
      line.erase(0, 6);
      n = line;

      getline(fileStu, line);
      line.erase(0, 6);
      y = line;

      getline(fileStu, line);
      line.erase(0, 7);
      m = line;

      getline(fileStu, line);
      line.erase(0, 5);
      g = stod(line);

      line = "";
      getline(fileStu, line);
      line.erase(0, 12);
      sID = stoi(line);

      getline(fileStu, line);
      line.erase(0, 12);
      fID = stoi(line);

      Student s(n, y, m, g, sID, fID);
      masterStudent ->insert(s);
    }
  }
//checks file
  if (fileFac.is_open() && fileFac.good())
  {
    while (!fileFac.eof())
    {
      string n = "", l = "", s = "";
      int fID = 0;
      getline(fileFac, line);
      if (line.empty())
        continue;
      line.erase(0, 6);
      n = line;
      getline(fileFac, line);
      line.erase(0, 7);
      l = line;
      getline(fileFac, line);
      line.erase(0, 12);
      s = line;
      getline(fileFac, line);
      line.erase(0, 12);
      fID = stod(line);
      Faculty f(n, l, s, fID);
      getline(fileFac, line);
      line.erase(0, 15);
      if (line.empty())
      {
        masterFaculty->insert(f);
        continue;
      }
      stringstream iss(line);
      while (iss >> line)

      masterFaculty->insert(f);
    }
  }
  fileStu.close();
  fileFac.close();
}
//case statements for each option
void Database::dbOptionsOut()
{
  while (true)
  {
    string input = "";
//student
    string firstS = "";
//faculty
    string secondF = "";
    cout <<  "---Enter number to select an option---\n" << endl;
    cout <<  "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout <<  "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout <<  "3. Find and display student information given the students id" << endl;
    cout <<  "4. Find and display faculty information given the faculty id" << endl;
    cout <<  "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout <<  "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout <<  "7. Add a new student" << endl;
    cout <<  "8. Delete a student given the id" << endl;
    cout <<  "9. Add a new faculty member" << endl;
    cout <<  "10. Delete a faculty member given the id" << endl;
    cout <<  "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout <<  "12. Remove an advisee from a faculty member given the ids" << endl;
    cout <<  "13. Rollback" << endl;
    cout <<  "14. Exit" << endl;

    cin >> input;

    switch (stoi(input))
    {

      case 1:
      {
        masterStudent ->printTree();
        break;
      }

      case 2:
      {
        masterFaculty->printTree();
        break;
      }

      case 3:
      {
        cout << "Enter student ID:" << endl;
        cin >> firstS;
        if (masterStudent ->search(stoi(firstS)))
          cout << masterStudent ->search(stoi(firstS))->key << endl;
        else
          cout << "STUDENT DOES NOT EXIST" << endl;
        break;
      }

      case 4:
      {
        cout << "Enter faculty ID:" << endl;
        cin >> firstS;
        if (masterFaculty->search(stoi(firstS)))
          cout << masterFaculty->search(stoi(firstS))->key << endl;
        else
          cout << "FACULTY MEMEBR DOES NOT EXIST" << endl;
        break;
      }

      case 5:
      {
        cout << "Enter student ID:" << endl;
        cin >> firstS;
        int temp = stoi(firstS);
        if (masterStudent ->search(temp))
        {
          if (masterFaculty->search(masterStudent ->search(temp)->key.facID))
            cout << (masterFaculty->search(masterStudent ->search(temp)->key.facID)->key) << endl;
          else
            cout << "FACULTY DOES NOT EXIST" << endl;
        }
        else
          cout << "STUDENT DOES NOT EXIST" << endl;
        break;

      }

      case 6:
      {
        cout << "Enter faculty member ID:" << endl;
        cin >> firstS;
        if (masterFaculty->search(stoi(firstS)))
        {

        }
        else
          cout << "FACULTY MEMBER DOES NOT EXIST" << endl;
        break;
      }

      case 7:
      {
        string name = "", year = "", major = "";
        double gpa = 0;
        int stuID = 0;
        int facID = 0;
        cin.ignore();
        cout << "Enter student name:" << endl;
        getline(cin, name);
        cout << "Enter student year:" << endl;
        getline(cin, year);
        cout << "Enter student major:" << endl;
        getline(cin, major);
        cout << "Enter student gpa:" << endl;
        getline(cin, firstS);
        gpa = stod(firstS);
        cout << "Enter student ID:" << endl;
        getline(cin, firstS);
        stuID = stoi(firstS);

        if (!masterStudent ->search(stuID))
        {
          masterStudent ->insert(Student(name, year, major, gpa, stuID, -1)); //insert student with no faculty member
          Faculty f;
        }
        else
          cout << "STUDENT ALREADY EXIST IN Database" << endl;
        break;
      }

      case 8:
      {
        cout << "Enter student ID:" << endl;
        cin >> firstS;
        int temp = stoi(firstS);
        if (masterStudent ->search(temp))
        {
          if (masterStudent ->search(temp)->key.facID == -1)
          {
            Faculty f;

            masterStudent ->deleteNode(temp);
          }
          else
            cout << "REMOVAL ERROR" << endl;
        }
        else
          cout << "STUDENT DOES NOT EXIST" << endl;
        break;
      }

      case 9:
      {
        string name = "", level = "", department = "";
        int facID = 0;
        cin.ignore();
        cout << "Enter faculty member name:" << endl;
        getline(cin, name);
        cout << "Enter faculty member level:" << endl;
        getline(cin, level);
        cout << "Enter faculty member department:" << endl;
        getline(cin, department);
        cout << "Enter faculty member ID:" << endl;
        getline(cin, firstS);
        facID = stoi(firstS);
        Faculty fa(name, level, department, facID);

        if (!masterFaculty->search(facID))
        {
          masterFaculty->insert(fa);
          Student s;

        }
        else
          cout << "FACULTY EXIST ALREADY IN Database" << endl;

        break;
      }

      case 10:
      {
        cout << "Enter faculty member ID:" << endl;
        cin >> firstS;
        int temp = stoi(firstS);
        if (masterFaculty->search(temp))
        {


            Student s;

            masterFaculty->deleteNode(temp);

            cout << "REMOVAL ERROR" << endl;
        }
        else
          cout << "FACULTY DOES NOT EXIST" << endl;
        break;
      }

      case 11:
      {
        cout << "Enter student ID:" << endl;
        cin >> firstS;
        cout << "Enter faculty member ID:" << endl;
        cin >> secondF;
        int temp1 = stoi(firstS);
        int temp2 = stoi(secondF);
        if (masterStudent ->search(temp1))
        {
          if (masterFaculty->search(temp2))
          {
            if (masterStudent ->search(stoi(firstS))->key.facID == -1)
            {
              masterStudent ->search(temp1)->key.facID = temp2;

              Faculty f;

            }
            else
              cout << "REMOVAL ERROR" << endl;
          }
          else
            cout << "FACULTY DOES NOT EXIST" << endl;
        }
        else
          cout << "STUDENT DOES NOT EXIST" << endl;
        break;
      }

      case 12:
      {
        cout << "Enter faculty member ID:" << endl;
        cin >> firstS;
        cout << "Enter student ID:" << endl;
        cin >> secondF;
        int temp1 = stoi(secondF);
        int temp2 = stoi(firstS);
        if (masterFaculty->search(temp2))
        {
          if (masterStudent ->search(temp1))
          {
            if (masterStudent ->search(temp1)->key.stuID == stoi(firstS))
            {
              masterStudent ->search(temp1)->key.stuID = -1;

            }
            else
              cout << "COULD NOT BE FOUND" << endl;
          }
          else
            cout << "STUDENT DOES NOT EXIST" << endl;
        }
          else
            cout << "FACULTY DOES NOT EXIST" << endl;
        break;
      }
//moves info to file
      case 13:
      {
        ofstream myStu;
        ofstream myFac;
        myStu.open("student.txt");
        myFac.open("faculty.txt");
        if (myStu.is_open())
          masterStudent ->treeToFile(myStu);
        if (myFac.is_open())
          masterFaculty->treeToFile(myFac);
        myStu.close();
        myFac.close();
        return;
      }
      default:
      {
        cout << "INVALID INPUT" << endl;
      }

    }
  }
}
