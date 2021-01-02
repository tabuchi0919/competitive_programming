#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b, c, ans = 1000;
  cin >> a >> b >> c;
  ans = min(ans, abs(a - b) + abs(b - c));
  ans = min(ans, abs(a - c) + abs(b - c));
  ans = min(ans, abs(a - b) + abs(a - c));
  cout << ans << endl;
}
