#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
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
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<ll>> dp(H + 1, vector<ll>(W, 0));
  dp[0][0] = 1ll;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      for(int bit = 0; bit < 1 << (W - 1); ++bit) {
        bool ok = true;
        for(int k = 0; k < W - 2; ++k) {
          if((bit & (1 << k)) && (bit & (1 << (k + 1))))
            ok = false;
        }
        if(!ok)
          continue;
        int nj = j;
        if(bit & (1 << j))
          nj = j + 1;
        else if(j > 0 && (bit & (1 << (j - 1))))
          nj = j - 1;
        dp[i + 1][nj] += dp[i][j];
        dp[i + 1][nj] %= MOD;
      }
    }
  }
  cout << dp[H][K - 1] << endl;
}
