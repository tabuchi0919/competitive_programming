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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> AB(N, vector<int>(N));

  REP(i, M) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    AB[A][B] = 1;
    AB[B][A] = 1;
  }
  REP(i, N) AB[i][i] = 1;

  vector<int> pre(1 << N), dp(1 << N, INF);
  REP(mask, 1 << N) {
    int ok = 1;
    REP(i, N) {
      REP(j, i) {
        if((mask & (1 << i)) && (mask & (1 << j))) {
          if(AB[i][j] == 0)
            ok = 0;
        }
      }
    }
    pre[mask] = ok;
  }
  REP(mask, 1 << N) {
    for(int mask2 = mask; mask2 > 0; mask2 = (mask2 - 1) & mask) {
      if(pre[mask] == 1) {
        dp[mask] = 1;
      } else {
        chmin(dp[mask], dp[mask - mask2] + dp[mask2]);
      }
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}
