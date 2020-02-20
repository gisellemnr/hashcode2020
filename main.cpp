#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "library.h"
using namespace std;


int score(lib l) {
  int bpd = l.bpd;

  int maxday = 0;
  for (int i = 0; i < bpd; i++) {
    maxday += get<0>(l.books[i]);
  }

  return maxday;
}

bool libCompare(const lib &l1, const lib &l2) {
  return score(l1) > score(l2);
}

int main() {
  int books, libs, days;
  cin >> books >> libs >> days;

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

  cout << num_libs << endl;
  days_spent = 0;
  for (int i = 0; i < num_libs; i++) {
    lib l = libraries[i];
    days_spent += l.delay;
    int days_left = days - days_spent;
    int books_scanned = l.bpd * days_left;
    if (books_scanned > l.books.size()) books_scanned = l.books.size();

    cout << l.id << " " << books_scanned << endl;
    for (int b = 0; b < books_scanned; b++) {
      cout << get<1>(l.books[b]) << " ";
    }
    cout << endl;
  }

  return 0;
}
