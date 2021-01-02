#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  string s, ans = "First";
  cin >> s;
  if((s.length() % 2 == 0) != (s[0] == s[s.length() - 1])) {
    ans = "Second";
  }
  cout << ans << endl;
}
