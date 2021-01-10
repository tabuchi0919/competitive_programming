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
  int N;
  cin >> N;
  map<int, int> mp;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    mp[A]++;
  }
  ll ans = COM(N, 3);
  for(auto e : mp) {
    ans -= COM(e.second, 2) * (N - e.second) % MOD;
    ans += MOD;
    ans -= COM(e.second, 3);
    ans += MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
