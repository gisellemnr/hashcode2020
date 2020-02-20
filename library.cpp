#include "library.h"


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
