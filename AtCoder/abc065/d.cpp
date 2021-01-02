#include <algorithm>
#include <iostream>
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

const int MOD = 1000000007;
typedef long long ll;

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
      swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> x(N), y(N);
  for(int i = 0; i < N; i++) {
    int tmpx, tmpy;
    cin >> tmpx >> tmpy;
    x[i] = make_pair(tmpx, i);
    y[i] = make_pair(tmpy, i);
  }

  vector<tuple<int, int, int>> edges;
  edges.reserve(210000);
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for(int i = 0; i < N - 1; i++) {
    edges.push_back(
        make_tuple(x[i + 1].first - x[i].first, x[i].second, x[i + 1].second));
    edges.push_back(
        make_tuple(y[i + 1].first - y[i].first, y[i].second, y[i + 1].second));
  }

  sort(edges.begin(), edges.end());
  UnionFind uf(N);
  ll ans = 0;

  for(auto p : edges) {
    int c, i, j;
    tie(c, i, j) = p;

    if(!uf.issame(i, j)) {
      uf.merge(i, j);
      ans += c;
    }
  }
  cout << ans << endl;
}
