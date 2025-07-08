#include "myLib/allowNameSpaces.hpp"
#include "myLib/myStructure.hpp"
#include "myLib/myStructureManager.hpp"
#include "myLib/utility.hpp"
#include <cstdlib>
#include <limits>

using std::cin;
using std::system;

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

void menuAddTask(void)
{

  string description;
  system("clear");
  cout << "New task" << endl;
  cout << "----------------------------" << endl;
  cout << "Description:";
  // Descartar caracteres restantes en el búfer de entrada
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, description);
  cout << "Descripcion:(" << description << ")" << endl;
  description = trim(description);
  cout << "Descripcion:(" << description << ")" << endl;

  if (description.size() > 1)
  {
    myStructureManager *myAllTasks = new myStructureManager();
    if (myAllTasks)
    {
      myAllTasks->add(&description);

      myAllTasks->list();
      delete myAllTasks;
    }
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
      cout << "option 2" << endl;
      break;
    }
    case 3:
    {
      cout << "option 3" << endl;
      break;
    }
    case 4:
    {
      cout << "option 4" << endl;
      break;
    }
    case 5:
    {
      cout << "option 5" << endl;
      exit(0);
    }
    }
  } //--main while

  myStructureManager *myAllTasks = new myStructureManager();

  string descriptionFirstTask = "my first task";
  myAllTasks->add(&descriptionFirstTask);

  string descriptionSecondTask = "my second task";
  myAllTasks->add(&descriptionSecondTask);

  myAllTasks->list();

  cout << "myStructureManager" << endl;
}