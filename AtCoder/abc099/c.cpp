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
  int N;
  cin >> N;
  vector<ll> dp(N + 1, 100000);
  vector<ll> pow6(10), pow9(10);
  dp[0] = 0;
  pow6[0] = 1;
  pow9[0] = 1;
  for(int i = 0; i < 9; i++) {
    pow6[i + 1] = 6 * pow6[i];
    pow9[i + 1] = 9 * pow9[i];
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < 8; j++) {
      if(i - pow6[j] >= 0) {
        dp[i] = min(dp[i], dp[i - pow6[j]] + 1);
      }
      if(i - pow9[j] >= 0) {
        dp[i] = min(dp[i], dp[i - pow9[j]] + 1);
      }
    }
  }
  cout << dp[N] << endl;
}
