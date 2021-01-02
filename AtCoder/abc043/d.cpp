#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans1 = -1, ans2 = -1, n;

  n = s.length();
  for(int i = 0; i < n - 1; i++) {
    if(s[i] == s[i + 1]) {
      ans1 = i + 1;
      ans2 = i + 2;
      break;
    }
  }
  for(int i = 0; i < n - 2; i++) {
    if(s[i] == s[i + 2]) {
      ans1 = i + 1;
      ans2 = i + 3;
      break;
    }
  }

  cout << ans1 << " " << ans2 << endl;
}
