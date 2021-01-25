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

int N, M, K;
int A[101010];
int NG[101010];
long double dp[202020], S[202020];
long double solve(double v) {
  int i;

  for(i = N - 1; i >= 0; i--) {
    if(NG[i]) {
      dp[i] = v;
    } else {
      dp[i] = 1 + (S[i + 1] - S[i + 1 + M]) / M;
    }
    S[i] = S[i + 1] + dp[i];
  }
  return dp[0];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> N >> M >> K;
  int p = -1, cur = 0;
  REP(i, K) {
    cin >> A[i];
    if(p + 1 != A[i])
      cur = 0;
    p = A[i];
    NG[A[i]] = 1;
    cur++;
    if(cur == M) {
      cout << -1 << endl;
      return 0;
    }
  };
  long double L = 0, R = 1e12;
  REP(i, 300) {
    long double M = (L + R) / 2;
    if(solve(M) > M)
      L = M;
    else
      R = M;
  }
  cout << setprecision(15) << L << endl;
}
