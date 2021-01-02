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

pair<int, int> operator+(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  pair<int, int> p = {lhs.first + rhs.first, lhs.second + rhs.second};
  return p;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, H) cin >> S[i];
  int ans = 0;
  const pair<int, int> moves[] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };
  REP(i, H) {
    REP(j, W) {
      // スタートをi,jにする
      queue<pair<int, int>> q;
      vector<vector<int>> field(H, vector<int>(W, -1));
      if(S[i][j] == '#')
        continue;

      q.emplace(i, j);
      field[i][j] = 0;
      while(!q.empty()) {
        auto now = q.front();
        q.pop();
        for(auto e : moves) {
          auto next = now + e;
          if(next.first < 0 || next.first >= H || next.second < 0 ||
             next.second >= W || S[next.first][next.second] == '#' ||
             field[next.first][next.second] != -1)
            continue;

          q.push(next);
          field[next.first][next.second] = field[now.first][now.second] + 1;
          chmax(ans, field[next.first][next.second]);
        }
      }
    }
  }
  cout << ans << endl;
}
