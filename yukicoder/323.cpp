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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int H, W, A, Si, Sj, B, Gi, Gj;
  cin >> H >> W >> A >> Si >> Sj >> B >> Gi >> Gj;
  vector<string> M(H);
  REP(i, H) cin >> M[i];

  vector<vector<vector<bool>>> ans(H,
                                   vector<vector<bool>>(W, vector<bool>(4000)));

  queue<tuple<int, int, int>> q;
  q.push(tie(Si, Sj, A));

  const pair<int, int> moves[] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while(!q.empty()) {
    tuple<int, int, int> cur = q.front();
    q.pop();
    for(auto &move : moves) {
      int x = get<0>(cur);
      int y = get<1>(cur);
      int s = get<2>(cur);
      int nextx = x + move.first;
      int nexty = y + move.second;
      if(nextx < 0 || nexty < 0 || nextx >= H || nexty >= W) {
        continue;
      }
      int nexts = s + (M[nextx][nexty] == '*' ? 1 : -1);
      if(nexts <= 0 || nexts >= 3800) {
        continue;
      }
      if(!ans[nextx][nexty][nexts]) {
        ans[nextx][nexty][nexts] = true;
        q.push(tie(nextx, nexty, nexts));
      }
    }
  }
  cout << (ans[Gi][Gj][B] ? "Yes" : "No") << endl;
}
