#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
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
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  int N, M;
  cin >> N >> M;
  UnionFind uf(N);
  for(int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    uf.merge(x, y);
  }
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(i == uf.root(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}
