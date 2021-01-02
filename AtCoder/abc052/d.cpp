#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int n, a, b, ans = 0;
  cin >> n >> a >> b;
  vector<long long int> x(n);
  for(int i = 0; i < n; i++) {
    cin >> x[i];
    if(i > 0) {
      ans += min(a * (x[i] - x[i - 1]), b);
    }
  }
  cout << ans << endl;
}
