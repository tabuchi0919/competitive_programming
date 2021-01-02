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
  int N, M, ans = 0;
  cin >> N >> M;
  vector<vector<int>> graph(N, vector<int>(N));
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  REP(bit, (1 << N)) {
    vector<int> S;
    REP(i, N) {
      if(bit & (1 << i))
        S.push_back(i);
    }
    int L = S.size();
    bool flag = true;
    REP(i, L) {
      REP(j, i) {
        if(graph[S[i]][S[j]] == 0)
          flag = false;
      }
    }
    if(flag)
      ans = max(ans, L);
  }

  cout << ans << endl;
}
