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
#include <unordered_map>
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

unordered_map<ll, int> prime_factor(ll n) {
  unordered_map<ll, int> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1)
    ret[n] = 1;
  return ret;
}

ll RepeatSquaring(ll N, ll P, ll M) {
  if(P == 0)
    return 1;
  if(P % 2 == 0) {
    ll t = RepeatSquaring(N, P / 2, M);
    return t * t % M;
  }
  return N * RepeatSquaring(N, P - 1, M);
}

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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> A(N);
  unordered_map<ll, int> gcd;
  REP(i, N) cin >> A[i];
  REP(i, N) {
    unordered_map<ll, int> mp = prime_factor(A[i]);
    for(auto e : mp) {
      gcd[e.first] = max(gcd[e.first], e.second);
    }
  }
  ll ans = 0ll, l = 1ll;
  for(auto e : gcd) {
    ll f = e.first;
    ll s = e.second;
    l *= RepeatSquaring(f, s, MOD);
    l %= MOD;
  }
  REP(i, N) {
    ans += l * modinv(A[i], MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
