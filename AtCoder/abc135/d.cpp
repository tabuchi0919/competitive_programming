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
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();

  vector<vector<ll>> dp(13, vector<ll>(N, 0));

  reverse(ALL(S));
  if(S[0] == '?') {
    for(int i = 0; i < 10; i++) {
      dp[i][0] = 1ll;
    }
  } else {
    dp[(int)S[0] - 48][0] = 1ll;
  }

  vector<ll> mo(N);
  mo[0] = 1;
  for(int i = 1; i < N; i++) {
    mo[i] = (mo[i - 1] * 10) % 13;
    if(S[i] == '?') {
      for(int j = 0; j < 10; j++) {
        int tmp = mo[i] * j % 13;
        for(int k = 0; k < 13; k++) {
          dp[(k + tmp) % 13][i] += dp[k][i - 1];
          dp[(k + tmp) % 13][i] %= MOD;
        }
      }
    } else {
      int tmp = mo[i] * ((int)S[i] - 48) % 13;
      for(int j = 0; j < 13; j++) {
        dp[(j + tmp) % 13][i] += dp[j][i - 1];
        dp[(j + tmp) % 13][i] %= MOD;
      }
    }
  }
  cout << dp[5][N - 1] << endl;
}
