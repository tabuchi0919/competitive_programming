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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> field(H + 2, vector<int>(W + 2));
  vector<vector<char>> ans(H, vector<char>(W));
  REP(i, H) {
    string s;
    cin >> s;
    REP(j, W) {
      if(s[j] == '#') {
        field[i + 1][j + 1] = 1;
      }
    }
  }
  REP(i, H) {
    REP(j, W) {
      int cnt = 0;
      if(field[i + 1][j + 1] == 1) {
        ans[i][j] = '#';
      } else {
        FOR(k, -1, 2) {
          FOR(l, -1, 2) {
            if(field[i + 1 + k][j + 1 + l] == 1)
              cnt++;
          }
        }
        ans[i][j] = cnt + '0';
      }
    }
  }
  REP(i, H) {
    REP(j, W) { cout << ans[i][j]; }
    cout << endl;
  }
}
