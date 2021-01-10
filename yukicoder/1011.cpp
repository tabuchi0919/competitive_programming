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
  ll n, d, k;
  cin >> n >> d >> k;
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
  dp[0][0] = 1;
  REP(i, n) {
    vector<ll> sum(k + 1);
    REP(j, k) {
      sum[j + 1] = sum[j] + dp[i][j];
      sum[j + 1] %= MOD;
    }
    REP(j, k + 1) {
      dp[i + 1][j] = sum[j] - sum[max(0ll, j - d)];
      dp[i + 1][i] %= MOD;
    }
  }
  cout << (dp[n][k] % MOD + MOD) % MOD << endl;
}
