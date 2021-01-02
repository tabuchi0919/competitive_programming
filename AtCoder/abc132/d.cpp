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

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if(n < k)
    return 0;
  if(n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long FAC(int n) { return fac[n]; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  COMinit();
  int N, K;
  cin >> N >> K;
  if(N != K) {
    for(int i = 1; i <= K; i++) {
      cout << COM(K - 1, i - 1) *
                  (((COM(N - K - 1, i - 1) * 2 + COM(N - K - 1, i)) % MOD +
                    COM(N - K - 1, i - 2)) %
                   MOD) %
                  MOD
           << endl;
    }
  } else {
    cout << 1 << endl;
    for(int i = 2; i <= K; i++) {
      cout << 0 << endl;
    }
  }
}
