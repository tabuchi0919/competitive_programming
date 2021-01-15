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

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if(par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y)
      return false;
    if(par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> ABY;
  REP(i, M) {
    int a, b, y;
    cin >> a >> b >> y;
    a--;
    b--;
    ABY.emplace_back(a, b, y);
  }
  UnionFind uf(N);
  sort(ALL(ABY), [](auto const &lhs, auto const &rhs) {
    return get<2>(lhs) > get<2>(rhs);
  });
  int Q;
  cin >> Q;
  vector<int> ans(Q);
  vector<tuple<int, int, int>> vwq;
  REP(i, Q) {
    int v, w;
    cin >> v >> w;
    v--;
    vwq.emplace_back(v, w, i);
  }
  sort(ALL(vwq), [](auto const &lhs, auto const &rhs) {
    return get<1>(lhs) > get<1>(rhs);
  });
  int cur = 0;
  REP(i, Q) {
    while(get<2>(ABY[cur]) > get<1>(vwq[i])) {
      uf.merge(get<0>(ABY[cur]), get<1>(ABY[cur]));
      cur++;
      if(cur == M)
        break;
    }
    ans[get<2>(vwq[i])] = uf.size(get<0>(vwq[i]));
  }
  REP(i, Q) cout << ans[i] << endl;
}
