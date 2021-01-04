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
  int N;
  cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  REP(i, N) REP(j, N) cin >> A[i][j];
  vector<ll> pre(1 << N), dp(1 << N);
  REP(mask, 1 << N) {
    REP(i, N) {
      REP(j, i) {
        if((mask & (1 << i)) && (mask & (1 << j))) {
          pre[mask] += A[i][j];
        }
      }
    }
  }
  REP(mask, 1 << N) {
    REP(mask2, 1 << N) {
      int mask3 = mask2 & mask;
      chmax(dp[mask], dp[mask - mask3] + pre[mask3]);
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}
