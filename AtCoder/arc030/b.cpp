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

using Graph = vector<vector<int>>;

Graph G;
vector<int> h;

int dfs(int v, int p) {
  // サブツリーのコスト
  int cost = 0;
  for(auto next : G[v]) {
    if(next == p)
      continue;
    int sub_cost = dfs(next, v);
    cost += sub_cost;
  }
  if(cost != 0 || h[v] == 1) {
    cost += 2;
  }
  return cost;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  x--;
  G.assign(n, vector<int>());
  h.assign(n, 0);
  REP(i, n) { cin >> h[i]; }
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cout << max(0, dfs(x, -1) - 2) << endl;
}
