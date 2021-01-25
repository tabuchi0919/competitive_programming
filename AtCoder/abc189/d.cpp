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
  vector<string> S(N);
  REP(i, N) cin >> S[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(2));
  dp[0][0] = 1;
  dp[0][1] = 1;
  REP(i, N) {
    if(S[i] == "AND") {
      dp[i + 1][0] = dp[i][1] + 2 * dp[i][0];
      dp[i + 1][1] = dp[i][1];
    } else {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][0] + dp[i][1] * 2;
    }
  }
  cout << dp[N][1] << endl;
}
