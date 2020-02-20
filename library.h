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

void printlib (lib l) {
  cout << "Delay: " << l.delay << endl;
  cout << "Books per day: " << l.bpd << endl;

  cout << "Books: [";
  for (int i = 0; i < l.books.size(); i++) {
    tuple<int,int> t = l.books[i];
    cout << "(" << get<0>(t) << "," << get<1>(t) << ") ";
  }
  cout << "]" << endl;
}
#endif
