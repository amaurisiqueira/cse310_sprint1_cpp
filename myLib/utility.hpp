

#ifndef MY_UTILITY
#define MY_UTILITY

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::stringstream;
using std::vector;

string trim(const string &str);
vector<string> split(const string &str, char delimiter);

void PressAnyKey(void);

#endif