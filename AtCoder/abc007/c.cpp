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

pair<int, int> operator+(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  pair<int, int> p = {lhs.first + rhs.first, lhs.second + rhs.second};
  return p;
}

bool operator==(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

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
  int R, C, sy, sx, gy, gx;
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<vector<bool>> field(R, vector<bool>(C, false));
  vector<vector<int>> ans(R, vector<int>(C, -1));

  REP(i, R) {
    string c;
    cin >> c;
    REP(j, C) { field[i][j] = (c[j] == '.'); }
  }

  queue<pair<int, int>> q;
  ans[sy][sx] = 0;
  q.push(make_pair(sy, sx));

  const pair<int, int> moves[] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for(auto &move : moves) {
      pair<int, int> next = cur + move;
      if(ans[next.first][next.second] == -1 && field[next.first][next.second]) {
        ans[next.first][next.second] = ans[cur.first][cur.second] + 1;
        q.push(next);
      }
    }
  }
  cout << ans[gy][gx] << endl;
}
