#include <algorithm>
#include <deque>
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

void dfs(int v, int p, ll d, vector<ll> &depth,
         vector<vector<pair<int, ll>>> &tree) {
  depth[v] = d;
  for(auto &e : tree[v]) {
    if(e.first == p)
      continue;
    dfs(e.first, v, d + e.second, depth, tree);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<pair<int, ll>>> tree(N);
  vector<ll> depth(N);
  for(int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    tree[a].push_back(make_pair(b, c));
    tree[b].push_back(make_pair(a, c));
  }
  int Q, K;
  cin >> Q >> K;
  K--;

  dfs(K, -1, 0, depth, tree);
  for(int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << depth[x] + depth[y] << endl;
  }
}
