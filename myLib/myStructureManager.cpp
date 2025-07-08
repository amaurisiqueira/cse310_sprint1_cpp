#include "myStructureManager.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::left;
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
myStructureManager::myStructureManager()
{
  // initialize a vector with all tasks
  allTasks = new vector<Task_t>();
  cout << "constructor of ManagerStructureClass\n";
}

myStructureManager::~myStructureManager()
{

  // check if a pointer is initailized and free memory
  if (allTasks)
    delete allTasks;

  cout << "Destructor of ManagerStructureClass\n";
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