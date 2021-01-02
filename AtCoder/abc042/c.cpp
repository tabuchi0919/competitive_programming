#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  for(int i = 0; i < k; i++) {
    cin >> d[i];
  }
  for(int i = n; i < 100000; i++) {
    if((i / 10000 == 0 || find(d.begin(), d.end(), i / 10000) == d.end()) &&
       (i / 1000 == 0 || find(d.begin(), d.end(), i / 1000 % 10) == d.end()) &&
       (i / 100 == 0 || find(d.begin(), d.end(), i / 100 % 10) == d.end()) &&
       (i / 10 == 0 || find(d.begin(), d.end(), i / 10 % 10) == d.end()) &&
       find(d.begin(), d.end(), i % 10) == d.end()) {
      cout << i << endl;
      break;
    }
  }
}
