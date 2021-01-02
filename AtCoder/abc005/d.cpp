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
  int N, Q;
  cin >> N;

  vector<vector<int>> D(N, vector<int>(N, 0));
  REP(i, N) {
    REP(j, N) { cin >> D[i][j]; }
  }

  vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));
  REP(i, N) {
    REP(j, N) {
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + D[i][j];
    }
  }

  vector<int> maxs(N * N + 1);
  FOR(i, 1, N + 1) {
    FOR(j, 1, N + 1) {
      // i,jが長方形のサイズ
      REP(k, N - i + 1) {
        REP(l, N - j + 1) {
          chmax(maxs[i * j],
                sum[i + k][j + l] - sum[i + k][l] - sum[k][j + l] + sum[k][l]);
        }
      }
    }
  }
  REP(i, N * N) { maxs[i + 1] = max(maxs[i], maxs[i + 1]); }

  cin >> Q;
  REP(i, Q) {
    int p;
    cin >> p;
    cout << maxs[p] << endl;
  }
}
