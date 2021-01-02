#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int N, H, ans = 0;
  cin >> N >> H;
  vector<int> a(N), b(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  for(int i = 0; i < N; i++) {
    if(H <= 0 || b[i] < a[0])
      break;
    H -= b[i];
    ans++;
  }

  if(H > 0) {
    ans += (H + a[0] - 1) / a[0];
  }

  cout << ans << endl;
}
