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
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<pair<ll, ll>> XY(M);
  REP(i, M) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    XY[i] = {x, y};
  }
  sort(ALL(XY));
  vector<ll> dp(N, INFLL);
  REP(i, M) {
    ll X, Y;
    X = XY[i].first;
    Y = XY[i].second;
    chmin(dp[Y], min(dp[X], A[X]));
  }
  ll ans = -INFLL;
  // REP(i, N) cout << dp[i] << endl;
  REP(i, N) { chmax(ans, A[i] - dp[i]); }
  cout << ans << endl;
}
