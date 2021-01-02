#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  string ans = "NO";
  cin >> a >> b >> c;
  if(a == 5 && b == 5 && c == 7) {
    ans = "YES";
  } else if(a == 5 && b == 7 && c == 5) {
    ans = "YES";
  } else if(a == 7 && b == 5 && c == 5) {
    ans = "YES";
  }
  cout << ans << endl;
}
