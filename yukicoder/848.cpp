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
  ll N, M, P, Q, T;
  cin >> N >> M >> P >> Q >> T;
  P--;
  Q--;
  vector<vector<Edge<ll>>> edges(N);
  for(int i = 0; i < M; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }
  auto ans1 = Dijkstra(edges, 0);
  auto ansq = Dijkstra(edges, Q);
  auto ansp = Dijkstra(edges, P);
  ll p1 = ans1[P], q1 = ans1[Q], pq = ansq[P];
  if(p1 * 2 > T || q1 * 2 > T) {
    cout << -1 << endl;
  } else if(p1 + q1 + pq <= T) {
    cout << T << endl;
  } else {
    ll ans = INFLL;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if((ans1[i] + max(ansp[i] + ansp[j], ansq[i] + ansq[j]) + ans1[j]) <=
           T) {
          ans = min(ans, max(ansp[i] + ansp[j], ansq[i] + ansq[j]));
        }
      }
    }
    cout << T - ans << endl;
  }
}
