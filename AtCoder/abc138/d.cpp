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

using Graph = vector<vector<int>>;

int N;
Graph G;

vector<int> res;

void dfs(int v, int p) {
  if(p != -1)
    res[v] += res[p];
  for(auto nv : G[v]) {
    if(nv == p)
      continue;
    dfs(nv, v);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  G.assign(N, vector<int>());
  res.assign(N, 0);
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  REP(i, Q) {
    int p, x;
    cin >> p >> x;
    p--;
    res[p] += x;
  }

  dfs(0, -1);

  REP(i, N - 1) { cout << res[i] << " "; }
  cout << res[N - 1] << endl;
}
