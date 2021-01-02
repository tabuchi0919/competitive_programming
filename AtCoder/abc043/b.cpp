#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string s, ans = "";
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == 'B' && ans.length() > 0) {
      ans.pop_back();
    } else if(s[i] != 'B') {
      ans.push_back(s[i]);
    }
  }
  cout << ans << endl;
}
