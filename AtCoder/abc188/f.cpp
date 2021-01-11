#include <algorithm>
#include <cassert>
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

unordered_map<ll, ll> memo;
ll X, Y;

ll solve(ll y) {
  ll ret;
  if(memo[y] != 0)
    return memo[y];
  if(y == 1) {
    ret = abs(X - y);
  } else if(y % 2) {
    ret = min({abs(X - y), solve((y + 1) / 2) + 2, solve((y - 1) / 2) + 2});
  } else {
    ret = min(abs(X - y), solve(y / 2) + 1);
  }
  memo[y] = ret;
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> X >> Y;
  cout << solve(Y) << endl;
}
