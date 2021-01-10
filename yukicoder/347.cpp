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
  int B;
  cin >> B;
  vector<long double> a(N);
  // 微分の方
  long double ans = 0, ans2 = 0;
  ll tmp = 1;
  REP(i, N) cin >> a[i];
  REP(i, N) { ans += powl(B, a[i] - 1) * a[i]; }
  REP(i, N) {
    if(a[i] != -1) {
      ans2 += powl(B, a[i] + 1) / (a[i] + 1);
    } else {
      ans2 += logl(B);
    }
  }
  cout << setprecision(15) << ans << endl;
  cout << setprecision(15) << ans2 << endl;
}
