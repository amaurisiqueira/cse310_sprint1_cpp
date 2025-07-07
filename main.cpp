#include "myLib/allowNameSpaces.hpp"
#include "myLib/myStructure.hpp"
#include "myLib/myStructureManager.hpp"
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
  cout << "2 | Edit a task" << endl;
  cout << "3 | Delete a task" << endl;
  cout << "4 | List all tasks" << endl;
  cout << "5 | Exit of program" << endl;
}

// get a valid menu option
int getMenuOption(void)
{

  int option_selected = 0;
  do
  {
    myMenu();
    cout << "\n\nPlease choice a option between 1 and 5: ";
    cin >> option_selected;
    if (cin.fail())
    {
      cout << "Invalid number. Please try again!" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

  } while (option_selected < 1 || option_selected > 5);

  return option_selected;
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