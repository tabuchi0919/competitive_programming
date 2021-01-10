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

ll ans = 0ll;

ll gcd(ll a, ll b) {
  if(a % b == 0) {
    ans += a / b;
    return (b);
  } else {
    ans += 1ll + a / b;
    return (gcd(b, a % b));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  gcd(m, n);
  cout << ans - 1 << endl;
}
