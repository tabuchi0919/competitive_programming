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
  int R, G, B;
  cin >> R >> G >> B;
  ll ans = INFLL;
  FOR(lg, -2000, 2000) {
    ll tmp = 0;
    int rg = lg + G - 1;
    FOR(g, lg, rg + 1) { tmp += abs(g); }
    int rr;
    if((R - 1) / 2 <= lg + 99) {
      rr = -100 + (R - 1) / 2;
    } else {
      rr = lg - 1;
    }
    int lr = rr - R + 1;
    FOR(r, lr, rr + 1) { tmp += abs(r + 100); }

    int lb;
    if((B - 1) / 2 <= 99 - rg) {
      lb = 100 - (B - 1) / 2;
    } else {
      lb = rg + 1;
    }
    int rb = lb + B - 1;
    FOR(b, lb, rb + 1) { tmp += abs(b - 100); }
    chmin(ans, tmp);
  }
  cout << ans << endl;
}
