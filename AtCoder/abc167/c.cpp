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
  int N, M, X;
  cin >> N >> M >> X;
  vector<vector<ll>> A(N, vector<ll>(M));
  vector<ll> C(N);
  REP(i, N) {
    cin >> C[i];
    REP(j, M) { cin >> A[i][j]; }
  }
  ll ans = INFLL;
  REP(bit, (1 << N)) {
    vector<ll> tmp(M);
    ll cost = 0;
    REP(i, N) {
      if(bit & (1 << i)) {
        REP(j, M) { tmp[j] += A[i][j]; }
        cost += C[i];
      }
    }
    bool flag = true;
    REP(j, M) {
      if(tmp[j] < X)
        flag = false;
    }
    if(flag)
      chmin(ans, cost);
  }

  cout << (ans == INFLL ? -1 : ans) << endl;
}
