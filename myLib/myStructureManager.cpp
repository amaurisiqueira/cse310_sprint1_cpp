#include "myStructureManager.hpp"
#include "utility.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::left;
using std::ofstream;
using std::right;
using std::setfill;
using std::setw;
/*
struct Task_t
{
  int id;
  string description;
  bool completed;
}*/

// implementation of constructor
myStructureManager::myStructureManager(const string filename_)
{
  // initialize a vector with all tasks
  allTasks = new vector<Task_t>();
  filename = filename_;
  cout << "constructor of ManagerStructureClass\n";
  ifstream file(filename);
  if (file)
  {
    string line;
    // run over a file, from begin to the end file.
    while (getline(file, line))
    {

      // sepate a content of string
      vector<string> substrings = split(line, '|');

      // check if there are 3 elements
      if (substrings.size() >= 3)
      {
        int id = atol(substrings[0].c_str());
        //
        bool completed = atoi(substrings[1].c_str()) == 1 ? true : false;
        string description = substrings[2];
        if (add(id, completed, &description))
        {
          cout << "Loaded ID:" << id;
        }
      }
    }
  }
  file.close();
}

myStructureManager::~myStructureManager()
{

  // check if a pointer is initailized and free memory
  if (allTasks)
  {

    ofstream file(filename);
    // try to open a file
    if (file)
    {
      for (int a = 0; a < allTasks->size(); a++)
      {
        file << (*allTasks)[a].id << "|" << ((*allTasks)[a].completed ? "1" : "0") << "|" << (*allTasks)[a].description << std::endl;
      }
      file.close();
      // cout << "El archivo se creo correctamente." << endl;
    }
    delete allTasks;
  }

  //  cout << "Destructor of ManagerStructureClass\n";
}

// load tasks from file
bool myStructureManager::loadTaskFromFile(string *fileName)
{

  return true;
}

// save tasks to file
bool myStructureManager::saveTaskToFile(string *fileName)
{

  return true;
}

// list all tasks
void myStructureManager::list(void)
{

  cout << "****** Start Elements in Task buffer *******" << endl;

  cout << " ID | Completed |  Description of task" << endl;
  cout << "--------------------------------------" << endl;
  for (int a = 0; a < allTasks->size(); a++)
  {

    cout << setw(4) << right << setfill('0') << (*allTasks)[a].id << "| " << left << setw(10) << setfill(' ') << ((*allTasks)[a].completed ? "Yes" : "No ") << "| " << (*allTasks)[a].description << std::endl;
  }
  cout << "--------------------------------------" << endl;
  cout << "****** End   Elements in Task buffer *******" << endl;
}

// add new task to buffer
bool myStructureManager::add(string *description)
{
  // if is invalid pointer, return false
  if (!allTasks)
    return false;

  int id = 0;
  // looking for a last ID
  for (int a = 0; a < allTasks->size(); a++)
  {
    // if in task id is greater than my current ID
    if ((*allTasks)[a].id > id)
    {
      id = (*allTasks)[a].id;
    }
  }
  id++;

  Task_t myNewElement;
  myNewElement.id = id;
  myNewElement.completed = false;
  myNewElement.description = *description;

  allTasks->push_back(myNewElement);

  return true;
}

// add new task to buffer
bool myStructureManager::add(int id, bool completed, string *description)
{
  // if is invalid pointer, return false
  if (!allTasks)
    return false;

  Task_t myNewElement;
  myNewElement.id = id;
  myNewElement.completed = completed;
  myNewElement.description = *description;

  allTasks->push_back(myNewElement);

  return true;
}

bool myStructureManager::complete(int myID)
{

  // if is invalid pointer, return false
  if (!allTasks)
    return false;

  int id = 0;
  // looking for a last ID
  for (int a = 0; a < allTasks->size(); a++)
  {
    // if in task id is equal my current ID
    if ((*allTasks)[a].id == myID)
    {
      // change status of my task
      (*allTasks)[a].completed = true;
      break;
    }
  }

  return true;
}

bool myStructureManager::del(int myID)
{

  // if is invalid pointer, return false
  if (!allTasks)
    return false;

  // looking for a last ID
  for (auto it = allTasks->begin(); it != allTasks->end(); ++it)
  {
    if (it->id == myID)
    {
      // Delete a task
      allTasks->erase(it);
      break;
    }
  }

  return true;
}