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
  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A), q(B), r(C), s(X + Y + C);
  REP(i, A) cin >> p[i];
  REP(i, B) cin >> q[i];
  REP(i, C) cin >> r[i];
  sort(rALL(p));
  sort(rALL(q));
  sort(rALL(r));
  REP(i, X) s[i] = p[i];
  REP(i, Y) s[i + X] = q[i];
  REP(i, C) s[i + X + Y] = r[i];
  sort(rALL(s));
  cout << accumulate(s.begin(), s.begin() + X + Y, 0ll) << endl;
}
