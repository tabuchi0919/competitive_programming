#include <algorithm>
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
  vector<ll> a(M), b(M), c(M, 0);
  REP(i, M) {
    cin >> a[i] >> b[i];
    REP(j, b[i]) {
      int t;
      cin >> t;
      t--;
      c[i] += (1 << t);
    }
  }
  vector<vector<ll>> dp(M + 1, vector<ll>(1 << N, INFLL));
  dp[0][0] = 0;

  REP(i, M) {
    REP(j, 1 << N) {
      chmin(dp[i + 1][j], dp[i][j]);
      int nj = j | c[i];
      chmin(dp[i + 1][nj], dp[i][j] + a[i]);
    }
  }
  ll ans = dp[M][(1 << N) - 1];
  if(ans == INFLL) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
