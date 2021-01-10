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
  int N, M, A;
  cin >> N >> M >> A;
  vector<vector<pair<int, ll>>> E(N);
  REP(i, M) {
    int r, l, p;
    cin >> r >> l >> p;
    r--;
    l--;
    E[l].emplace_back(r, p);
  }
  vector<ll> dp(N + 1);
  ll ma = 0;
  REP(i, N) {
    dp[i + 1] = ma - A;
    for(auto e : E[i]) {
      chmax(dp[i + 1], dp[e.first] + e.second - (i == N - 1 ? 0 : A));
    }
    ma = max(ma, dp[i + 1]);
  }
  cout << ma << endl;
}
