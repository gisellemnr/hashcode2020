#ifndef _SOL_H
#define _SOL_H
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

struct solution
{
  std::vector<int> libraries;
  std::map<int, std::vector<int> > books_per_library;
};

void print_solution(solution *sol);

#endif
