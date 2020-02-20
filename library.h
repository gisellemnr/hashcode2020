#ifndef _LIB_H
#define _LIB_H

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;
struct lib {
  int id;
  int delay;
  int bpd; // books per day
  vector<tuple<int,int> > books;
};

void printlib (lib l);
#endif
