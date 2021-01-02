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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll a, b, x;
  cin >> a >> b >> x;
  ll n = 0, ans = 0;
  FOR(d, 1, 10) {
    ll m = (x - d * b) / a;
    if(to_string(m).length() == d) {
      ans = max(ans, m);
    } else if(to_string(m).length() > d) {
      string str(d, '9');
      ans = max(ans, stoll(str));
    }
  }
  if(a * 1000000000 + b * 10 <= x)
    ans = 1000000000;
  cout << ans << endl;
}
