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
  ll ans = 0;
  cin >> N;
  vector<vector<ll>> cnt(9, vector<ll>(9));
  FOR(i, 1, N + 1) {
    string s = to_string(i);
    int f = s.front() - '0', b = s.back() - '0';
    if(f != 0 && b != 0) {
      cnt[f - 1][b - 1]++;
    }
  }
  REP(i, 9) {
    REP(j, 9) { ans += cnt[i][j] * cnt[j][i]; }
  }
  cout << ans << endl;
}
