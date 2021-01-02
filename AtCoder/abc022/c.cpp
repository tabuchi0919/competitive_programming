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

template <class T = ll> struct Edge {
  int to;
  T cost;
  Edge() {}
  Edge(int to, T cost) : to(to), cost(cost) {}
  bool operator>(const Edge &r) const { return this->cost > r.cost; }
};

template <class T = ll>
vector<T> Dijkstra(vector<vector<Edge<T>>> &edges, int st) {

  int V = (int)edges.size();
  vector<T> dist(V, INF);
  dist[st] = 0;

  priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> p_que;
  p_que.emplace(st, dist[st]);

  while(!p_que.empty()) {

    Edge<T> now(p_que.top().to, p_que.top().cost);
    p_que.pop();

    if(dist[now.to] < now.cost)
      continue;
    for(const Edge<T> &e : edges[now.to]) {
      T tmp_cost = now.cost + e.cost;
      if(dist[e.to] > tmp_cost) {
        dist[e.to] = tmp_cost;
        p_que.emplace(e.to, dist[e.to]);
      }
    }
  }

  return dist;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<vector<Edge<int>>> edges(N);
  vector<Edge<int>> tonari;
  REP(i, M) {
    int u, v, l;
    cin >> u >> v >> l;
    u--;
    v--;
    if(u == 0) {
      tonari.emplace_back(v, l);
    } else {
      edges[u].emplace_back(v, l);
      edges[v].emplace_back(u, l);
    }
  }
  int cnt = tonari.size();
  int ans = INF;
  REP(i, cnt) {
    auto dijkstra = Dijkstra<int>(edges, tonari[i].to);
    REP(j, i) {
      if(dijkstra[tonari[j].to] == INF)
        continue;
      ans = min(ans, dijkstra[tonari[j].to] + tonari[i].cost + tonari[j].cost);
    }
  }
  if(ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
