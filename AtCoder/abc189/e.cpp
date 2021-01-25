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

struct point {
  ll space[3];
};

struct matrix {
  ll space[3][3];

  matrix operator*(const matrix &another) const {
    matrix ans;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        ans.space[i][j] = 0;
        for(int k = 0; k < 3; k++) {
          ans.space[i][j] += space[i][k] * another.space[k][j];
        }
      }
    }
    return ans;
  }

  point operator*(const point &another) const {
    point ans;
    REP(i, 3) {
      ans.space[i] = space[i][0] * another.space[0] +
                     space[i][1] * another.space[1] +
                     space[i][2] * another.space[2];
    }
    return ans;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<point> xy(N);
  REP(i, N) {
    ll x, y;
    cin >> x >> y;
    xy[i] = {x, y, 1};
  }
  int M;
  cin >> M;
  vector<matrix> ops(M + 1);
  ops[0] = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
  matrix op1 = {{{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}};
  matrix op2 = {{{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}};
  matrix op3 = {{{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
  matrix op4 = {{{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}};
  REP(i, M) {
    int op;
    cin >> op;
    if(op == 1) {
      ops[i + 1] = op1 * ops[i];
    }
    if(op == 2) {
      ops[i + 1] = op2 * ops[i];
    }
    if(op == 3) {
      cin >> op3.space[0][2];
      op3.space[0][2] *= 2;
      ops[i + 1] = op3 * ops[i];
    }
    if(op == 4) {
      cin >> op4.space[1][2];
      op4.space[1][2] *= 2;
      ops[i + 1] = op4 * ops[i];
    }
  }
  int Q;
  cin >> Q;
  REP(i, Q) {
    int a, b;
    cin >> a >> b;
    b--;
    point ans = ops[a] * xy[b];
    cout << ans.space[0] << " " << ans.space[1] << endl;
  }
}
