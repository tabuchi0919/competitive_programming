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
  int N, ans = 0, now = 1;
  cin >> N;
  vector<int> a(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  while(true) {
    ans++;
    now = a[now];
    if(now == 2) {
      cout << ans << endl;
      break;
    }
    if(ans > 100010) {
      cout << -1 << endl;
      break;
    }
  }
}
