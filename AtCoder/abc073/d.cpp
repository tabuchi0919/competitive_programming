#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
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
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r(R);
  vector<vector<Edge<int>>> edges(N);
  REP(i, R) cin >> r[i];
  REP(i, R) r[i]--;
  REP(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }

  vector<vector<int>> ans(R, vector<int>(R));

  REP(i, R) {
    auto djk = Dijkstra<int>(edges, r[i]);
    REP(j, R) { ans[i][j] = djk[r[j]]; }
  }

  vector<int> tmp(R);
  REP(i, R) tmp[i] = i;

  int now = INF;

  do {
    int cnt = 0;
    REP(i, R - 1) { cnt += ans[tmp[i]][tmp[i + 1]]; }
    now = min(now, cnt);
  } while(next_permutation(ALL(tmp)));

  cout << now << endl;
}
