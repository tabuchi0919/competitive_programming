#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int left = 0, right = w, upper = h, lower = 0;
  for(int i = 0; i < n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if(a == 1)
      left = max(left, x);
    if(a == 2)
      right = min(right, x);
    if(a == 3)
      lower = max(lower, y);
    if(a == 4)
      upper = min(upper, y);
  }
  int ans = 0;
  if(right > left && lower < upper)
    ans = (right - left) * (upper - lower);
  cout << ans << endl;
}
