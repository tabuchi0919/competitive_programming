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

template <class T> struct Edge {
  int from, to;
  T cost;
  Edge() {}
  Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <class T>
vector<T> Bellman_Ford(const vector<Edge<T>> &edges, const int V,
                       const int st) {

  const T inf = numeric_limits<T>::max() / 2;
  vector<T> cost(V, inf);
  cost[st] = 0;
  for(int i = 0; i < V - 1; i++) {
    for(const auto &e : edges) {
      if(cost[e.from] == inf)
        continue;
      cost[e.to] = min(cost[e.to], cost[e.from] + e.cost);
    }
  }

  for(int i = 0; i < V; i++) {
    for(const auto &e : edges) { // finding negative loop
      if(cost[e.from] == inf)
        continue;
      if(cost[e.from] == -inf)
        cost[e.to] = -inf; // src is nloop -> dst is nloop
      else if(cost[e.to] > cost[e.from] + e.cost)
        cost[e.to] = -inf; // chmin is possible -> nloop
    }
  }

  return cost;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<Edge<ll>> g;
  REP(i, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c = -c;
    g.emplace_back(a, b, c);
  }
  auto ans = Bellman_Ford(g, N, 0);
  if(ans[N - 1] == -(numeric_limits<ll>::max() / 2)) {
    cout << "inf" << endl;
  } else {
    cout << -ans[N - 1] << endl;
  }
}
