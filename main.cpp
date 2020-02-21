#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

using namespace std;

int DAYS = 0;
map<int,int> book_copies;

int score(lib l) {
  /* Attempt 0 and 3 -- worse than next
  int bpd = l.bpd;
  int maxday = 0;
  for (int i = 0; i < bpd && i < l.books.size(); i++) {
    maxday += get<0>(l.books[i]);
  }
  return maxday;
  */

  /* Attempts 1 and 2
  double s = (l.books.size() * l.bpd) / ((double) l.delay);
  return s;
  */

  /* Attempt 4 random! terrible idea
  srand( time(NULL));
  return rand() + 1;
  */

  /* Attempt 5 -- best scenario, send all books it can
  int can_send = (DAYS - l.delay) * l.bpd;
  int s = 0;
  for (int i = 0; i < can_send && i < l.books.size(); i++) {
    s += get<0>(l.books[i]);
  }
  return s;
  */

  // Attempt 6 -- books that many libraries have weight less (bit better)
  /*int can_send = (DAYS - l.delay) * l.bpd;
  int s = 0;
  for (int i = 0; i < can_send && i < l.books.size(); i++) {
    int bid = get<1>(l.books[i]);
    int bs = get<0>(l.books[i]);
    s += bs / book_copies[bid];
  }
  return s/l.delay;*/

  /* Attempt 7 -- do not take book copies into account...
  int can_send = (DAYS - l.delay) * l.bpd;
  int s = 0;
  for (int i = 0; i < can_send && i < l.books.size(); i++) {
    int bid = get<1>(l.books[i]);
    int bs = get<0>(l.books[i]);
    s += bs;
  }
  return s/l.delay;
  */

  // Attempt 8 
  int can_send = (DAYS - l.delay) * l.bpd;
  double s = 0;
  for (int i = 0; i < can_send && i < l.books.size(); i++) {
    int bid = get<1>(l.books[i]);
    int bs = get<0>(l.books[i]);
    s += ((double) bs);
  }
  return s/((double)l.delay);

}

bool libCompare(const lib &l1, const lib &l2) {
  return score(l1) > score(l2);
}

int main() {
  int books, libs, days;
  cin >> books >> libs >> days;
  DAYS = days;

  vector<int> book_scores;
  for (int i = 0; i < books; i++) {
    int score;
    cin >> score;
    book_scores.push_back(score);
  }

  vector<lib> libraries;
  for (int i = 0; i < libs; i++) {
    int bks, delay, bpd;
    cin >> bks >> delay >> bpd;

    lib l;
    l.id = i;
    l.delay = delay;
    l.bpd = bpd;

    vector<tuple<int,int> > bv;
    for (int j = 0; j < bks; j++) {
      int b;
      cin >> b;
      bv.push_back(make_pair(book_scores[b], b));

      if (book_copies.find(b) == book_copies.end()) {
        book_copies[b] = 1;
      }
      else {
        book_copies[b]++;
      }
    }
    // Libraries store their books in decreasing order of score
    sort(bv.rbegin(), bv.rend());

    l.books = bv;
    //printlib (l);
    libraries.push_back(l);
  }

  // Sort the libraries
  sort(libraries.begin(), libraries.end(), libCompare);

  // Generate output file given the sorted libraries
  int days_spent = 0;
  int num_libs = 0;
  while (days_spent < days && num_libs < libs) {
    lib l = libraries[num_libs];
    num_libs++;
    days_spent += l.delay;
  }

  map<int, bool> sent;
  for (int i = 0; i < books; i++) {
    sent[i] = false;
  }

  cout << num_libs << endl;

  days_spent = 0;
  for (int i = 0; i < num_libs; i++) {
    lib l = libraries[i];
    days_spent += l.delay;
    int days_left = days - days_spent;
    int books_scanned = l.bpd * days_left;
    if (books_scanned > l.books.size()) books_scanned = l.books.size();

    int b = 0;
    int bi = 0;
    vector<int> books_to_send;
    while (b < books_scanned) {
      int bid = get<1>(l.books[bi]);
      if (!sent[bid]) {
        books_to_send.push_back(bid);
        sent[bid] = true;
        b++;
      }

      bi++;
      if (bi >= l.books.size()) break;
    }


    // Printing only
    if (books_to_send.size() > 0) {
      cout << l.id << " " << books_to_send.size() << endl;
      for (int i = 0; i < books_to_send.size(); i++) {
        cout << books_to_send[i] << " ";
      }
      cout << endl;
    }
    else {
      num_libs++;
    }
  }

  return 0;
}
