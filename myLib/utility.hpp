

#ifndef MY_UTILITY
#define MY_UTILITY
#include <iostream>

using std::string;
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

#endif