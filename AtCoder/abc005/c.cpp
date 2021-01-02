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
  int T, N, M;
  cin >> T >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  cin >> M;
  vector<int> B(M);
  REP(i, M) cin >> B[i];
  int ans = true;
  REP(i, M) {
    REP(j, N) {
      if(B[i] - A[j] <= T && 0 <= B[i] - A[j]) {
        A[j] = -100000;
        break;
      }
      if(j == N - 1)
        ans = false;
    }
  }
  if(ans) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
