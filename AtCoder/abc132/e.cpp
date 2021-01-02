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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, S, T;
  cin >> N >> M;
  vector<vector<Edge<int>>> edges(3 * N);
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edges[u].emplace_back(v + N, 1);
    edges[u + N].emplace_back(v + 2 * N, 1);
    edges[u + 2 * N].emplace_back(v, 1);
  }
  cin >> S >> T;
  S--;
  T--;

  auto ans = Dijkstra<int>(edges, S);
  if(ans[T] == INF) {
    cout << -1 << endl;
  } else {
    cout << ans[T] / 3 << endl;
  }
}
