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
  int N, k;
  ll fac[100];
  fac[0] = fac[1] = 1ll;
  for(int i = 2; i < 100; i++) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  cin >> N >> k;
  vector<ll> a(k);
  for(int i = 0; i < k; i++)
    cin >> a[i];
  a.push_back(0);
  a.push_back((1ll << N) - 1);
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  ll ans = 1ll;
  for(int i = 0; i < a.size() - 1; i++) {
    if((a[i + 1] & a[i]) == a[i]) {
      ans *= fac[__builtin_popcountll(a[i + 1] - a[i])];
      ans %= MOD;
    } else {
      ans *= 0;
    }
  }
  cout << ans << endl;
}
