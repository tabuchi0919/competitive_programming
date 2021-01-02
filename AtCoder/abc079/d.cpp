#include <algorithm>
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

const int MOD = 1000000007;
typedef long long ll;

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
  const int INF = numeric_limits<T>::max();
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
  int H, W;
  cin >> H >> W;
  vector<vector<Edge<int>>> edges(10);

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      int c;
      cin >> c;
      edges[j].emplace_back(i, c);
    }
  }
  auto dij = Dijkstra<int>(edges, 1);

  vector<int> cost;
  for(auto &i : dij) {
    cost.push_back(i);
  }

  int ans = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int tmp;
      cin >> tmp;
      if(tmp != -1) {
        ans += cost[tmp];
      }
    }
  }
  cout << ans << endl;
}
