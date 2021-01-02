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

void dfs(vector<int> e, int N, int M, int Q, int &ans, vector<int> &A,
         vector<int> &B, vector<int> &C, vector<int> &D) {
  if(e.size() == N) {
    int tmp = 0;
    REP(i, Q) {
      if(e[B[i]] - e[A[i]] == C[i]) {
        tmp += D[i];
      }
      chmax(ans, tmp);
    }
  } else {
    FOR(i, e[e.size() - 1], M + 1) {
      vector<int> ee = e;
      ee.push_back(i);
      dfs(ee, N, M, Q, ans, A, B, C, D);
    }
    return;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> A(Q), B(Q), C(Q), D(Q);
  REP(i, Q) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--;
    B[i]--;
  }
  int ans = 0;
  vector<int> e(1);
  FOR(i, 1, 10) {
    e[0] = i;
    dfs(e, N, M, Q, ans, A, B, C, D);
  }
  cout << ans << endl;
}
