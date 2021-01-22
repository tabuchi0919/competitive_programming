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
  vector<ll> A(N);
  vector<vector<ll>> B(N, vector<ll>(N));
  REP(i, N) { cin >> A[i]; }
  REP(i, N) {
    REP(j, N) { cin >> B[i][j]; }
  }
  ll ans = -INFLL, ans_mask = 0;
  FOR(mask, 1, 1 << N) {
    ll sum = 0;
    REP(i, N) {
      if(mask & (1 << i))
        sum += A[i];
    }
    REP(i, N) {
      REP(j, i) {
        if((mask & (1 << i)) && (mask & (1 << j)))
          sum += B[i][j];
      }
    }
    if(chmax(ans, sum)) {
      ans_mask = mask;
    }
  }
  cout << ans << endl;
  vector<int> anss;
  REP(i, N) {
    if(ans_mask & (1 << i))
      anss.push_back(i + 1);
  }
  REP(i, anss.size() - 1) { cout << anss[i] << " "; }
  cout << anss[anss.size() - 1] << endl;
}
