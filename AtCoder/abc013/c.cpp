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
  ll N, H, A, B, C, D, E, ans = INFLL;
  cin >> N >> H >> A >> B >> C >> D >> E;
  REP(i, N + 1) {
    // iは豪華な食事を摂る日数, xは質素な食事を摂る日数
    ll x = max(ll((N * E - i * E - i * B - H * 1.0) / (D + E) + 1), 0ll);
    if(i + x <= N)
      chmin(ans, A * i + C * x);
  }
  cout << ans << endl;
}
