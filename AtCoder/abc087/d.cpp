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

struct Edge {
  int now, to, cost;
  Edge() {}
  Edge(int now, int to, int cost) : now(now), to(to), cost(cost) {}
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<Edge>> edges(N);
  vector<int> points(N, INF);
  REP(i, M) {
    int l, r, d;
    cin >> l >> r >> d;
    l--;
    r--;
    edges[l].emplace_back(l, r, d);
    edges[r].emplace_back(r, l, -d);
  }

  queue<Edge> q;

  bool ans = true;
  for(int i = 0; i < N; i++) {
    if(points[i] == INF) {
      points[i] = 0;
      for(Edge e : edges[i])
        q.push(e);
    }
    while(!q.empty()) {
      Edge edge = q.front();
      q.pop();
      int now = edge.now;
      int to = edge.to;
      if(points[to] == INF) {
        points[to] = edge.cost + points[now];
        for(Edge e : edges[to])
          q.push(e);
      } else {
        if(points[to] != edge.cost + points[now])
          ans = false;
      }
    }
  }

  cout << (ans ? "Yes" : "No") << endl;
}
