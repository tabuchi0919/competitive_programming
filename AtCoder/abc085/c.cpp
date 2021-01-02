#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, y;
  int ansi = -1, ansj = -1, ansk = -1;
  cin >> n >> y;
  for(int i = 0; i < n + 1; i++) {
    for(int j = 0; j < n + 1 - i; j++) {
      if(10000 * i + 5000 * j + 1000 * (n - i - j) == y) {
        ansi = i;
        ansj = j;
        ansk = n - i - j;
      }
    }
  }
  cout << ansi << " " << ansj << " " << ansk << endl;
}
