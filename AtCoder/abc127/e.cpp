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
typedef long long ll;

const int MOD = 1000000007;
const int MAX = 500000;
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

long long FINV(int n) { return finv[n]; }

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while(b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if(u < 0)
    u += m;
  return u;
}

int main() {
  ll N, M, K;
  cin >> N >> M >> K;

  COMinit();

  ll sum = 0ll;
  for(int d = 0; d < N; d++) {
    sum += d * (N - d) * M * M;
    sum %= MOD;
  };
  for(int d = 0; d < M; d++) {
    sum += d * (M - d) * N * N;
    sum %= MOD;
  };
  cout << sum * COM(N * M - 2, K - 2) % MOD << endl;
}
