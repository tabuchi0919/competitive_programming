#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s, t, ans = "No";
  cin >> s >> t;
  int n = s.length();
  for(int i = 0; i < n + 1; i++) {
    if(s == t)
      ans = "Yes";
    s = s[n - 1] + s.substr(0, n - 1);
  }
  cout << ans << endl;
}
