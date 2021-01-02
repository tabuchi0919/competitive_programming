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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  vector<pair<int, int>> vp;
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    vp.emplace_back(a, b);
  }

  int cnt = 0;
  map<pair<int, int>, int> mp;
  vector<int> colors(N, 0);

  vector<bool> used(N, 0);
  queue<int> q;
  used[0] = true;
  q.push(0);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    chmax(cnt, (int)G[v].size());
    int color = 1;
    for(int u : G[v]) {
      if(used[u])
        continue;
      if(color == colors[v])
        color++;
      colors[u] = mp[make_pair(u, v)] = mp[make_pair(v, u)] = color;
      color++;
      used[u] = true;
      q.emplace(u);
    }
  }

  cout << cnt << endl;
  for(auto p : vp)
    cout << mp[p] << endl;
}
