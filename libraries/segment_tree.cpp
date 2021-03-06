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

template <typename Monoid> struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;

  int sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n)
      sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) { seg[k + sz] = x; }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1)
        L = f(L, seg[a++]);
      if(b & 1)
        R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const { return seg[k + sz]; }
};

int gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  SegmentTree<int> seg(
      N, [](int a, int b) { return gcd(a, b); }, 0);
  for(int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    seg.update(i, a);
  }
  int ans = max(seg.query(2, N + 1), seg.query(1, N));
  for(int i = 2; i < N; i++) {
    ans = max(gcd(seg.query(1, i), seg.query(i + 1, N + 1)), ans);
  }
  cout << ans << endl;
}
