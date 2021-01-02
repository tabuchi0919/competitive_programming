#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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

ll R, C, X, Y, D, L;

long long f(ll X, ll Y) { return COM(X * Y, D) * COM(X * Y - D, L) % MOD; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  COMinit();
  cin >> R >> C >> X >> Y >> D >> L;
  ll xy = (R - X + 1) * (C - Y + 1);
  if(X * Y == D + L) {
    cout << xy * f(X, Y) % MOD << endl;
  } else {
    cout << ((xy *
              (f(X, Y) - 2 * f(X - 1, Y) - 2 * f(X, Y - 1) +
               4 * f(X - 1, Y - 1) + f(X, Y - 2) + f(X - 2, Y) -
               2 * f(X - 1, Y - 2) - 2 * f(X - 2, Y - 1) + f(X - 2, Y - 2)) %
              MOD) %
                 MOD +
             MOD) %
                MOD
         << endl;
  }
}
