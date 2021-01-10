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
  ll N, K, X, Y;
  cin >> N >> K >> X >> Y;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
    A[i]--;
    A[i] = (A[i] + K - 1) / K;
  }
  //途中まで全部ベホマラー ベホマラー1回によりベホイミ○回のほうが効率的
  sort(rALL(A));
  if(Y <= X) {
    cout << A[0] * Y << endl;
  } else {
    ll a = (Y - 1) / X - 1;
    //上からa人はベホイミで削る
    if(a > N - 1) {
      //すべてベホイミ
      cout << accumulate(ALL(A), 0ll) * X << endl;
    } else {
      ll ans = A[a + 1] * Y;
      REP(i, a + 1) { ans += (A[i] - A[a + 1]) * X; }
      cout << ans << endl;
    }
  }
}
