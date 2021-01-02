#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string s, ans = "NO";
  cin >> s;
  reverse(s.begin(), s.end());
  while(true) {
    if(s == "") {
      ans = "YES";
      break;
    } else if(s.find("maerd") == 0 || s.find("esare") == 0) {
      s.erase(0, 5);
    } else if(s.find("remaerd") == 0) {
      s.erase(0, 7);
    } else if(s.find("resare") == 0) {
      s.erase(0, 6);
    } else {
      break;
    }
  }
  cout << ans << endl;
}
