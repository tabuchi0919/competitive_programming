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

vector<vector<int>> G(400000);
vector<int> used(400000);

// 木かどうかを返す
bool dfs(int v, int p) {
  used[v] = true;
  bool tree = true;
  for(auto nv : G[v]) {
    if(nv == p)
      continue;
    if(used[nv] || !dfs(nv, v)) {
      tree = false;
    }
  }
  return tree;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> ab(N);

  unordered_set<int> tmp;
  // 頂点数
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ab[i] = {a, b};
    G[a].push_back(b);
    G[b].push_back(a);
    tmp.insert(a);
    tmp.insert(b);
  }
  int ans = tmp.size();
  REP(i, N) {
    int start = ab[i].first;
    if(used[start])
      continue;
    if(dfs(start, -1)) {
      ans--;
    };
  }
  cout << ans << endl;
}
