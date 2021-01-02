#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const ll MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()

ll RepeatSquaring(ll N, ll P, ll M) {
  if(P == 0)
    return 1;
  if(P % 2 == 0) {
    ll t = RepeatSquaring(N, P / 2, M);
    return t * t % M;
  }
  return N * RepeatSquaring(N, P - 1, M);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string L;
  cin >> L;
  ll N = L.length();
  ll ans = 0ll;
  vector<vector<ll>> dp(2, vector<ll>(N + 1, 0ll));
  dp[0][0] = 1ll;
  dp[1][0] = 0ll;

  for(int i = 0; i < N; i++) {
    if(L[i] == '1') {
      dp[0][i + 1] = dp[0][i] * 2 % MOD;
      dp[1][i + 1] = dp[0][i] + dp[1][i] * 3 % MOD;
    } else {
      dp[0][i + 1] = dp[0][i] % MOD;
      dp[1][i + 1] = dp[1][i] * 3 % MOD;
    }
  }

  cout << (dp[0][N] + dp[1][N]) % MOD << endl;
}
