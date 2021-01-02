#include <bits/stdc++.h>

using namespace std;
int main() {
  long long int H, W, N;
  cin >> H >> W >> N;
  map<pair<long long int, long long int>, long long int> MLL;
  for(int i = 0; i < N; i++) {
    long long int a, b;
    cin >> a >> b;
    a--;
    b--;
    for(int j = -1; j <= 1; j++) {
      for(int k = -1; k <= 1; k++) {
        MLL[make_pair(a + j, b + k)]++;
      }
    }
  }
  vector<long long int> ans(10);
  for(auto n : MLL) {
    if(1 <= n.first.first && n.first.first < H - 1 && 1 <= n.first.second &&
       n.first.second < W - 1) {
      ans[n.second]++;
    }
  }
  ans[0] = (H - 2) * (W - 2);
  for(size_t i = 1; i < 10; i++) {
    ans[0] -= ans[i];
  }
  for(size_t i = 0; i < 10; i++) {
    cout << ans[i] << endl;
  }
}
