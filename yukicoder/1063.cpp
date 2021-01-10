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
  ll N;
  cin >> N;
  map<ll, int> mp = prime_factor(N);
  ll b = N, a = 1;
  for(auto e : mp) {
    REP(i, e.second / 2) {
      b /= (e.first * e.first);
      a *= e.first;
    }
  }
  cout << a << " " << b << endl;
}
