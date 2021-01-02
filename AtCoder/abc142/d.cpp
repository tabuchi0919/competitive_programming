#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
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

ll gcd(ll a, ll b) {
  if(a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

map<ll, int> prime_factor(ll n) {
  map<ll, int> ret;
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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll A, B;
  cin >> A >> B;
  ll d = gcd(A, B);
  map<ll, int> mp = prime_factor(d);
  int ans = 1;
  for(auto e : mp) {
    ans++;
  }
  cout << ans << endl;
}
