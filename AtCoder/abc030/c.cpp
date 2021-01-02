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
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> a(N), b(M);
  REP(i, N) cin >> a[i];
  REP(i, M) cin >> b[i];
  int ans = 0;
  int now = 0;
  while(true) {
    auto it1 = lower_bound(ALL(a), now);
    if(it1 == a.end())
      break;
    now = *it1 + X;
    auto it2 = lower_bound(ALL(b), now);
    if(it2 == b.end())
      break;
    now = *it2 + Y;
    ans++;
  }
  cout << ans << endl;
}
