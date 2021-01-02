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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<ll> dp(N + 1, 0);
  for(int i = 0; i < M; i++) {
    int a;
    cin >> a;
    dp[a] = -1;
  }
  dp[0] = 1;

  for(int i = 0; i < N; i++) {
    if(dp[i] == -1)
      continue;
    if(dp[i + 1] != -1)
      dp[i + 1] += dp[i];
    if(i + 2 <= N && dp[i + 2] != -1)
      dp[i + 2] += dp[i];
    dp[i + 1] %= MOD;
    dp[i + 2] %= MOD;
  }
  cout << dp[N] % MOD << endl;
}
