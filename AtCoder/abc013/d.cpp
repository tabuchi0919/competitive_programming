#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, D;
  cin >> N >> M >> D;
  vector<int> amida(N), B(M);
  vector<vector<int>> dp(30, vector<int>(N));
  for(int i = 0; i < M; i++) {
    cin >> B[i];
    B[i]--;
  }
  for(int i = 0; i < N; i++) {
    amida[i] = i;
  }
  for(int i = M - 1; i >= 0; i--) {
    swap(amida[B[i]], amida[B[i] + 1]);
  }

  for(int i = 0; i < N; i++) {
    dp[0][i] = amida[i];
  }

  for(int i = 0; i < 29; i++) {
    for(int j = 0; j < N; j++) {
      dp[i + 1][j] = dp[i][dp[i][j]];
    }
  }

  for(int i = 0; i < N; i++) {
    int now = i;
    for(int j = 0; j < 30; j++) {
      if((D & (1 << j)) != 0) {
        now = dp[j][now];
      }
    }
    cout << now + 1 << endl;
  }
}
