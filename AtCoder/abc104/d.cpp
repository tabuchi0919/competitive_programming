#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.length();
  ll dp[N + 1][4];
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= 3; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for(int i = 0; i < N; i++) {
    if(S[i] == 'A') {
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
      dp[i + 1][2] += dp[i][2];
      dp[i + 1][3] += dp[i][3];
      dp[i + 1][0] %= MOD;
      dp[i + 1][1] %= MOD;
      dp[i + 1][2] %= MOD;
      dp[i + 1][3] %= MOD;
    }
    if(S[i] == 'B') {
      dp[i + 1][2] += dp[i][1];
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
      dp[i + 1][2] += dp[i][2];
      dp[i + 1][3] += dp[i][3];
      dp[i + 1][0] %= MOD;
      dp[i + 1][1] %= MOD;
      dp[i + 1][2] %= MOD;
      dp[i + 1][3] %= MOD;
    }
    if(S[i] == 'C') {
      dp[i + 1][3] += dp[i][2];
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
      dp[i + 1][2] += dp[i][2];
      dp[i + 1][3] += dp[i][3];
      dp[i + 1][0] %= MOD;
      dp[i + 1][1] %= MOD;
      dp[i + 1][2] %= MOD;
      dp[i + 1][3] %= MOD;
    }
    if(S[i] == '?') {
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][2] += dp[i][1];
      dp[i + 1][3] += dp[i][2];
      dp[i + 1][0] += 3 * dp[i][0];
      dp[i + 1][1] += 3 * dp[i][1];
      dp[i + 1][2] += 3 * dp[i][2];
      dp[i + 1][3] += 3 * dp[i][3];
      dp[i + 1][0] %= MOD;
      dp[i + 1][1] %= MOD;
      dp[i + 1][2] %= MOD;
      dp[i + 1][3] %= MOD;
    }
  }
  cout << dp[N][3] << endl;
}
