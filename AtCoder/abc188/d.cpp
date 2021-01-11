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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll N, C;
  cin >> N >> C;
  vector<ll> a(N), b(N), c(N);
  REP(i, N) cin >> a[i] >> b[i] >> c[i];
  map<ll, ll> mp;
  REP(i, N) {
    a[i]--;
    b[i]--;
    mp[a[i]] += c[i];
    mp[b[i] + 1] -= c[i];
  }
  ll ans = 0, last_cost = 0, last_day = 0;
  for(auto e : mp) {
    ans += min(last_cost, C) * (e.first - last_day);
    last_cost += e.second;
    last_day = e.first;
  }
  cout << ans << endl;
}
