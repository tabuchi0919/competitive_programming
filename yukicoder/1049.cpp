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
  ll P, K;
  cin >> P >> K;
  vector<vector<ll>> dp(2, vector<ll>(K + 1));
  dp[0][0] = 1;
  REP(i, K) {
    dp[0][i + 1] += dp[0][i] * (P + 1);
    dp[0][i + 1] %= MOD;
    dp[0][i + 1] += dp[1][i] * 2;
    dp[0][i + 1] %= MOD;
    dp[1][i + 1] += dp[0][i] * (P - 1);
    dp[1][i + 1] %= MOD;
    dp[1][i + 1] += dp[1][i] * (2 * P - 2);
    dp[1][i + 1] %= MOD;
  }
  cout << dp[0][K] << endl;
}
