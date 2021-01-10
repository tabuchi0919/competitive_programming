#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];
  int ans = 0;
  REP(i, N) {
    REP(j, i) {
      // iとjを通る直線に通る数を数える
      int cnt = 2;
      REP(k, N) {
        if(k == i || k == j)
          continue;
        // kが通るかどうか
        cnt += ((Y[k] - Y[j]) * (X[k] - X[i]) == (X[k] - X[j]) * (Y[k] - Y[i]));
      }
      chmax(ans, cnt);
    }
  }

  cout << ans << endl;
}