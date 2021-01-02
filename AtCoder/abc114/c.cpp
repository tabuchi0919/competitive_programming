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
  int N, K, ans = 1000000010;
  cin >> N >> K;
  vector<int> h(N);
  for(int i = 0; i < N; i++)
    cin >> h[i];
  sort(h.begin(), h.end());
  for(int i = 0; i + K - 1 < N; i++) {
    ans = min(ans, h[i + K - 1] - h[i]);
  }
  cout << ans << endl;
}
