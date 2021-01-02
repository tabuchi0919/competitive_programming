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
  int N, K;
  cin >> N >> K;
  vector<int> pows(N + 1);
  vector<vector<int>> T(N, vector<int>(K));
  REP(i, N) REP(j, K) cin >> T[i][j];
  pows[0] = 1;
  REP(i, N) pows[i + 1] = pows[i] * K;
  bool ans = false;
  REP(i, pows[N]) {
    int tmp = 0;
    REP(j, N) {
      int now = (i / pows[j]) % pows[j + 1];
      tmp ^= T[j][now];
    }
    if(tmp == 0)
      ans = true;
  }
  cout << (ans ? "Found" : "Nothing") << endl;
}
