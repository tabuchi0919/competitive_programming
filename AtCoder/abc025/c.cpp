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

vector<vector<int>> b(2, vector<int>(3)), c(3, vector<int>(2));
unordered_map<string, pair<int, int>> memo;

pair<int, int> dfs(vector<string> S) {
  int turn = 0;
  if(memo.count(S[0] + S[1] + S[2]) == 1) {
    return memo[S[0] + S[1] + S[2]];
  }
  REP(i, 3) REP(j, 3) if(S[i][j] != '.') turn++;
  if(turn == 9) {
    // 全てが埋まってたらスコアを返す
    int choku = 0, nao = 0;
    REP(i, 2) {
      REP(j, 3) {
        if(S[i][j] == S[i + 1][j]) {
          choku += b[i][j];
        } else {
          nao += b[i][j];
        }
      }
    }
    REP(i, 3) {
      REP(j, 2) {
        if(S[i][j] == S[i][j + 1]) {
          choku += c[i][j];
        } else {
          nao += c[i][j];
        }
      }
    }
    pair<int, int> res = make_pair(choku, nao);
    memo[S[0] + S[1] + S[2]] = res;
    return res;
  } else {
    char next;
    if(turn % 2 == 0)
      next = 'o';
    else
      next = 'x';
    pair<int, int> res = {-1, -1};
    REP(i, 3) {
      REP(j, 3) {
        if(S[i][j] == '.') {
          S[i][j] = next;
          auto tmp = dfs(S);
          if(next == 'o') {
            if(res.first == -1) {
              res = tmp;
            } else {
              if(res.first - res.second < tmp.first - tmp.second)
                res = tmp;
            }
          } else {
            if(res.first == -1) {
              res = tmp;
            } else {
              if(res.second - res.first < tmp.second - tmp.first)
                res = tmp;
            }
          }
          S[i][j] = '.';
        }
      }
    }
    memo[S[0] + S[1] + S[2]] = res;
    return res;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<string> S = {"...", "...", "..."};
  REP(i, 2) REP(j, 3) cin >> b[i][j];
  REP(i, 3) REP(j, 2) cin >> c[i][j];
  auto ans = dfs(S);
  cout << ans.first << endl << ans.second << endl;
}
