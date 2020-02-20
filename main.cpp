#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct lib_t {
  int delay;
  int bpd; // books per day
  vector<tuple<int,int> > books;
} libraries [100000];

void printlib (lib_t l);

int main() {
  int books, libs, days;
  cin >> books >> libs >> days;

  vector<int> book_scores;
  for (int i = 0; i < books; i++) {
    int score;
    cin >> score;
    book_scores.push_back(score);
  }

  for (int i = 0; i < libs; i++) {
    int bks, delay, bpd;
    cin >> bks >> delay >> bpd;

    libraries[i].delay = delay;
    libraries[i].bpd = bpd;

    vector<tuple<int,int> > bv;
    for (int j = 0; j < bks; j++) {
      int b;
      cin >> b;
      bv.push_back(make_pair(book_scores[b], b));
    }
    sort(bv.rbegin(), bv.rend());

    libraries[i].books = bv;
    printlib (libraries[i]);
  }

  return 0;
}

void printlib (lib_t l) {
  cout << "Delay: " << l.delay << endl;
  cout << "Books per day: " << l.bpd << endl;

  cout << "Books: [";
  for (int i = 0; i < l.books.size(); i++) {
    tuple<int,int> t = l.books[i];
    cout << "(" << get<0>(t) << "," << get<1>(t) << ") ";
  }
  cout << "]" << endl;
}
