#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  for(int i = 0; i < n; i++) {
    cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  }

  string ans = "Yes";
  for(int i = 0; i < n; i++) {
    int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if((dist > t[i + 1] - t[i]) || ((abs(dist - t[i + 1] + t[i]) % 2) == 1)) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}
