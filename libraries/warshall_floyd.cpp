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

void warshall_floyd(int n, vector<vector<int>> &d) {
  REP(k, n) REP(i, n) REP(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> d(N, vector<int>(N, INF));
  REP(i, N) d[i][i] = 0;
  REP(i, M) {
    int a, b, t;
    cin >> a >> b >> t;
    a--;
    b--;
    d[a][b] = d[b][a] = t;
  }
  warshall_floyd(N, d);
  int ans = INF;
  REP(i, N) {
    int tmp = 0;
    REP(j, N) { chmax(tmp, d[i][j]); }
    chmin(ans, tmp);
  }
  cout << ans << endl;
}
