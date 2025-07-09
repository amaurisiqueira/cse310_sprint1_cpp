#include "utility.hpp"

string trim(const string &str)
{
  string::size_type inicio = str.find_first_not_of(" \t\n\r\f\v");
  if (inicio == string::npos)
  {
    return "";
  }
  string::size_type fin = str.find_last_not_of(" \t\n\r\f\v");
  return str.substr(inicio, fin - inicio + 1);
}
vector<string> split(const string &str, char delimiter)
{
  vector<string> result;
  stringstream ss(str);
  string item;

  while (getline(ss, item, delimiter))
  {
    result.push_back(item);
  }

  return result;
}

void PressAnyKey(void)
{
  cout << "Press Any key to continue..." << endl;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cin.get();
}
