#include <algorithm>
#include <deque>
#include <iomanip>
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
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()

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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    tmp--;
    p[i] = tmp;
  }

  UnionFind uf(N);

  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.merge(a, b);
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(uf.issame(i, p[i]))
      ans++;
  }
  cout << ans << endl;
}
