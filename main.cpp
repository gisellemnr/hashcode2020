#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct lib {
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

bool libCompare(const lib &l1, const lib &l2) {
  return true;
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

  return 0;
}

