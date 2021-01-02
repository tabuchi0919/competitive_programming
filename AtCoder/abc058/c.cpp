#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  for(int i = 0; i < n; i++) {
    cin >> S[i];
  }
  for(int i = 0; i < 26; i++) {
    long cnt = 50;
    for(int j = 0; j < n; j++) {
      cnt = min(cnt, count(S[j].cbegin(), S[j].cend(), 'a' + i));
    }
    for(int j = 0; j < cnt; j++) {
      cout << char('a' + i);
    }
  }
  cout << endl;
}
