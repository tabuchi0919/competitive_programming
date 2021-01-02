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
  int N, M;
  cin >> N >> M;
  vector<int> H(N), A(M), B(M);
  vector<bool> ans(N, true);
  REP(i, N) cin >> H[i];
  REP(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    if(H[A[i]] >= H[B[i]]) {
      ans[B[i]] = false;
    }
    if(H[B[i]] >= H[A[i]]) {
      ans[A[i]] = false;
    }
  }
  int a = 0;
  REP(i, N) { a += ans[i]; }
  cout << a << endl;
}
