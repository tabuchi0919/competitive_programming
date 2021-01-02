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

using namespace std;

template <class T> struct Edge {
  int to;
  T cost;
  Edge() {}
  Edge(int to, T cost) : to(to), cost(cost) {}
  bool operator>(const Edge &r) const { return this->cost > r.cost; }
};

template <class T>
vector<T> Dijkstra(const vector<vector<Edge<T>>> &edges, const int st) {

  const int V = (int)edges.size();
  const T inf = numeric_limits<T>::max() / 2;
  vector<T> cost(V, inf);
  cost[st] = 0;

  priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> pq;
  pq.emplace(st, cost[st]);

  while(!pq.empty()) {

    Edge<T> now(pq.top().to, pq.top().cost);
    pq.pop();

    if(cost[now.to] < now.cost)
      continue;
    for(const Edge<T> &e : edges[now.to]) {
      T tmp_cost = now.cost + e.cost;
      if(cost[e.to] > tmp_cost) {
        cost[e.to] = tmp_cost;
        pq.emplace(e.to, cost[e.to]);
      }
    }
  }

  return cost;
}

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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int u, v, len;
  vector<vector<Edge<int>>> edges(N);
  for(int i = 0; i < N - 1; i++) {
    cin >> u >> v >> len;
    u--;
    v--;
    edges[u].emplace_back(v, len);
    edges[v].emplace_back(u, len);
  }

  auto ans = Dijkstra<int>(edges, 0);

  for(auto &i : ans) {
    if(i % 2) {
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}
