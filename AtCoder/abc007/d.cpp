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
  ll a, b;
  cin >> a >> b;
  b++;
  string A = to_string(a), B = to_string(b);
  vector<vector<ll>> dp(2, vector<ll>(A.length() + 1, 0ll));
  vector<vector<ll>> dp2(2, vector<ll>(B.length() + 1, 0ll));
  dp[0][0] = 1;
  dp2[0][0] = 1;
  REP(i, A.length()) {
    int aa = A[i] - '0';
    REP(j, 10) {
      if(j != 4 && j != 9) {
        if(j < aa) {
          dp[1][i + 1] += dp[0][i] + dp[1][i];
        } else if(j == aa) {
          dp[1][i + 1] += dp[1][i];
          dp[0][i + 1] += dp[0][i];
        } else {
          dp[1][i + 1] += dp[1][i];
        }
      }
    }
  }
  REP(i, B.length()) {
    int bb = B[i] - '0';
    REP(j, 10) {
      if(j != 4 && j != 9) {
        if(j < bb) {
          dp2[1][i + 1] += dp2[0][i] + dp2[1][i];
        } else if(j == bb) {
          dp2[1][i + 1] += dp2[1][i];
          dp2[0][i + 1] += dp2[0][i];
        } else {
          dp2[1][i + 1] += dp2[1][i];
        }
      }
    }
  }
  cout << b - dp2[1][B.length()] - a + dp[1][A.length()] << endl;
}
