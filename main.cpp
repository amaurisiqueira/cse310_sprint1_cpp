#include "myLib/allowNameSpaces.hpp"
#include "myLib/myStructure.hpp"
#include "myLib/myStructureManager.hpp"
#include "myLib/utility.hpp"
#include <cstdlib>
#include <limits>

using std::cin;
using std::system;

const string FILENAME_TASK = "my_task.txt";

// list a menu
void myMenu(void)
{

  system("clear");
  cout << "Main Sprint 1 Amauri Siqueira" << endl;

  cout << "1 | Create a new task" << endl;
  cout << "2 | Complete a task" << endl;
  cout << "3 | Delete a task" << endl;
  cout << "4 | List all tasks" << endl;
  cout << "5 | Exit of program" << endl;

  cout << "\n\nPlease choice a option between 1 and 5: ";
}

// get a valid menu option
int getMenuOption(void)
{

  int option_selected = 0;
  do
  {
    // show a menu
    myMenu();

    // get user option
    cin >> option_selected;
    // check if has a fail when read a number.
    if (cin.fail())
    {
      cout << "Invalid number. Please try again!" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

  } while (option_selected < 1 || option_selected > 5);

  return option_selected;
}

//
void menuAddTask(void)
{
  string description;
  system("clear");
  cout << "New task" << endl;
  cout << "----------------------------" << endl;
  cout << "Description:";
  // remove all chactacer in buffer
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, description);
  // cout << "Descripcion:(" << description << ")" << endl;
  description = trim(description);
  // cout << "Descripcion:(" << description << ")" << endl;

  if (description.size() > 1)
  {
    // new instance of class myStructureManager
    myStructureManager *myAllTasks = new myStructureManager(FILENAME_TASK);
    if (myAllTasks)
    {
      // method to add a new task
      myAllTasks->add(&description);
      // destroy a instance of class myStructureManager
      delete myAllTasks;
    }
  }
}

//
void menuCompleTask(void)
{
  string myID;
  system("clear");
  cout << "Complete a task ID" << endl;
  cout << "----------------------------" << endl;
  cout << "ID to Complete:";
  // remove all chactacer in buffer
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, myID);
  // cout << "Descripcion:(" << description << ")" << endl;
  int id = atoi(trim(myID).c_str());
  // cout << "Descripcion:(" << description << ")" << endl;

  if (id > 0)
  {
    // new instance of class myStructureManager
    myStructureManager *myAllTasks = new myStructureManager(FILENAME_TASK);
    if (myAllTasks)
    {
      // method to complete a task
      myAllTasks->complete(id);
      // destroy a instance of class myStructureManager
      delete myAllTasks;
    }
  }
}

// de
void menuDeleteTask(void)
{
  string myID;
  system("clear");
  cout << "Delete a task by ID" << endl;
  cout << "----------------------------" << endl;
  cout << "ID to delete:";
  // remove all chactacer in buffer
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, myID);
  int id = atoi(trim(myID).c_str());
  if (id > 0)
  {
    // new instance of class myStructureManager
    myStructureManager *myAllTasks = new myStructureManager(FILENAME_TASK);
    if (myAllTasks)
    {
      // method to complete a task
      myAllTasks->del(id);
      // destroy a instance of class myStructureManager
      delete myAllTasks;
    }
  }
}
void menuListTask(void)
{
  myStructureManager *myAllTasks = new myStructureManager(FILENAME_TASK);
  if (myAllTasks)
  {
    myAllTasks->list();
    delete myAllTasks;

    // wait for a key to continue
    PressAnyKey();
  }
}

int main()
{

  while (true)
  {
    switch (getMenuOption())
    {
    case 1:
    {
      cout << "option 1" << endl;
      menuAddTask();
      break;
    }
    case 2:
    {

      menuCompleTask();
      break;
    }
    case 3:
    {
      menuDeleteTask();
      break;
    }
    case 4:
    {

      menuListTask();
      break;
    }
    case 5:
    {
      cout << "BYE!!!" << endl;
      exit(0);
    }
    }
  } //--main while
}