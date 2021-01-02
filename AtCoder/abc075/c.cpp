#include <algorithm>
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

void dfs(int now, int N, vector<bool> &seen, vector<vector<bool>> &graph) {
  seen[now] = true;
  REP(i, N) {
    if(graph[now][i] && !seen[i]) {
      dfs(i, N, seen, graph);
    };
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, M, ans = 0;
  cin >> N >> M;
  vector<vector<bool>> graph(N, vector<bool>(N));
  vector<int> a(M), b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    graph[a[i]][b[i]] = true;
    graph[b[i]][a[i]] = true;
  }
  REP(i, M) {
    graph[a[i]][b[i]] = false;
    graph[b[i]][a[i]] = false;
    vector<bool> seen(N);
    dfs(0, N, seen, graph);
    bool flag = false;
    REP(i, N) {
      if(seen[i] == false)
        flag = true;
    }
    ans += flag;
    graph[a[i]][b[i]] = true;
    graph[b[i]][a[i]] = true;
  }
  cout << ans << endl;
}
