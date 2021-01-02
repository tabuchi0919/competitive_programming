#include <algorithm>
#include <iostream>
#include <math.h>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, sum, size, ans = 0;
  double ave;
  cin >> n;
  vector<long long int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sum = accumulate(a.begin(), a.end(), 0);
  size = a.size();
  ave = round(double(sum) / size);
  for(int i = 0; i < n; i++) {
    ans += (a[i] - ave) * (a[i] - ave);
  }
  cout << ans << endl;
}
