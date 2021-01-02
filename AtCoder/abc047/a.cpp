#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  string ans = "No";
  cin >> a >> b >> c;
  if(a + b == c || a + c == b || a == b + c)
    ans = "Yes";
  cout << ans << endl;
}
