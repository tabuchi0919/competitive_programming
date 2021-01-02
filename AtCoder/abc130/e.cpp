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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, M;
  cin >> N >> M;
  vector<ll> S(N), T(M);
  vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
  vector<vector<ll>> dp2(N + 1, vector<ll>(M + 1, 0));
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    dp2[i][0] = 1ll;
  }
  for(int i = 0; i < M; i++) {
    cin >> T[i];
    dp2[0][i] = 1ll;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(S[i] == T[j]) {
        dp[i + 1][j + 1] = dp2[i][j] % MOD;
      }
      dp2[i + 1][j + 1] =
          (dp2[i][j + 1] + dp2[i + 1][j] - dp2[i][j] + dp[i + 1][j + 1] + MOD) %
          MOD;
    }
  }
  cout << (dp2[N][M] + 2) % MOD << endl;
}
