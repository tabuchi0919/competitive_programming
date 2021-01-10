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
  ll N, M, A, B;
  cin >> N >> M;
  vector<ll> V(N), R(M);
  vector<vector<ll>> dp1(2, vector<ll>(100001)), dp2(2, vector<ll>(100001));
  REP(i, N) cin >> V[i];
  REP(i, M) cin >> R[i];
  cin >> A >> B;
  dp1[0][0] = 1;
  dp2[0][0] = 1;

  REP(i, N) {
    // V[i]を使うかどうか
    REP(j, 100001) {
      if(j - V[i] >= 0) {
        dp1[(i + 1) % 2][j] = dp1[i % 2][j - V[i]] + dp1[i % 2][j];
      } else {
        dp1[(i + 1) % 2][j] = dp1[i % 2][j];
      }
      dp1[(i + 1) % 2][j] %= MOD;
    }
  }
  REP(i, M) {
    // R[i]を使うかどうか
    REP(j, 100001) {
      if(j - R[i] >= 0) {
        dp2[(i + 1) % 2][j] = dp2[i % 2][j - R[i]] + dp2[i % 2][j];
      } else {
        dp2[(i + 1) % 2][j] = dp2[i % 2][j];
      }
      dp2[(i + 1) % 2][j] %= MOD;
    }
  }
  vector<ll> v = dp1[N % 2], r = dp2[M % 2];
  vector<ll> Vsum(100002);
  REP(i, 100001) {
    Vsum[i + 1] = Vsum[i] + v[i];
    Vsum[i + 1] %= MOD;
  }
  ll ans = 0;
  REP(i, 100001) {
    ans += r[i] * (Vsum[min(100000ll, i * B + 1)] - Vsum[min(100000ll, i * A)]);
    ans %= MOD;
  }
  cout << (ans - 1 + MOD) % MOD << endl;
}
