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
  vector<vector<int>> A(N);
  unordered_map<int, int> mp;
  A[0].assign(1 << N, 0);
  REP(i, 1 << N) cin >> A[0][i];
  REP(i, 1 << N) { mp[A[0][i]] = i; }
  REP(i, N - 1) {
    A[i + 1].assign(1 << (N - 1 - i), 0);
    REP(j, 1 << (N - 1 - i)) {
      A[i + 1][j] = max(A[i][2 * j], A[i][2 * j + 1]);
    }
  }
  cout << mp[min(A[N - 1][0], A[N - 1][1])] + 1 << endl;
}
