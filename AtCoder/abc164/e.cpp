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
  vector<T> dist(V, INFLL);
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

  ll N, M, S;
  cin >> N >> M >> S;
  S = min(S, 5000ll);

  vector<ll> U(M), V(M), A(M), B(M), C(N), D(N);

  REP(i, M) {
    cin >> U[i] >> V[i] >> A[i] >> B[i];
    U[i]--;
    V[i]--;
  }
  REP(i, N) { cin >> C[i] >> D[i]; }

  // max5000枚にしてしまうと頂点数がN*5001
  // 頂点番号は都市番号i銀貨Sとして、i*5001+Sとする
  vector<vector<Edge<ll>>> edges(N * 5001);
  // 移動の辺
  REP(i, M) {
    REP(s, 5001) {
      // U[i]からV[i]に移動するとA[i]減らしながら、costはB[i]
      if(s - A[i] >= 0) {
        edges[U[i] * 5001 + s].emplace_back(V[i] * 5001 + s - A[i], B[i]);
        edges[V[i] * 5001 + s].emplace_back(U[i] * 5001 + s - A[i], B[i]);
      }
    }
  }

  // 両替の辺
  REP(i, N) {
    REP(s, 5000) {
      // sからC[i]枚増やすのにかかるcostがD[i]
      edges[i * 5001 + s].emplace_back(i * 5001 + min(5000ll, s + C[i]), D[i]);
    }
  }

  auto ans = Dijkstra<ll>(edges, S);

  FOR(i, 1, N) {
    ll tmp = INFLL;
    REP(s, 5001) { chmin(tmp, ans[i * 5001 + s]); }
    cout << tmp << endl;
  }
}
