#ifndef MY_STRUCTURE_MANAGER
#define MY_STRUCTURE_MANAGER
#include "myStructure.hpp"
#include <vector>

using std::string;
using std::vector;
/*
struct Task_t
{
  int id;
  string description;
  bool completed;
}*/

class myStructureManager
{
private:
  string filename;
  vector<Task_t> *allTasks;

public:
  // constructor
  myStructureManager(const string filename_);

  // destructor
  ~myStructureManager();

  // load tasks from file
  bool loadTaskFromFile(string *fileName);

  // save tasks to file
  bool saveTaskToFile(string *fileName);

  // list all tasks
  void list(void);

  // add new task to buffer
  bool add(string *description);
  // overload of function
  bool add(int id, bool completed, string *description);

  // method to complete a task
  bool complete(int myID);

  // method to delete a task
  bool del(int myID);
};

#endif