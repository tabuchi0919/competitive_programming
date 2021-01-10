#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

struct matrix {
  ll space[50][50];

  matrix operator*(const matrix &another) const {
    matrix ans;
    for(int i = 0; i < 50; i++) {
      for(int j = 0; j < 50; j++) {
        ans.space[i][j] = 0;
        for(int k = 0; k < 50; k++) {
          ans.space[i][j] += space[i][k] * another.space[k][j];
          ans.space[i][j] %= MOD;
        }
      }
    }
    return ans;
  }
};

const matrix A = {{{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};
const matrix E = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

matrix power(long exponent, matrix &A, matrix &E) {
  if(exponent % 2) {
    return power(exponent - 1, A, E) * A;
  } else if(exponent) {
    matrix root_ans = power(exponent / 2, A, E);
    return root_ans * root_ans;
  } else {
    return E;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll M, K;
  cin >> M >> K;
  matrix A, E;
  REP(i, M) {
    REP(j, M) { E.space[i][j] = (i == j); }
  }

  REP(i, M) {
    REP(j, M) {
      ll tmp = 0;
      // 足し算
      REP(k, M) { tmp += ((i + k) % M == j); }
      // 掛け算
      REP(k, M) { tmp += ((i * k) % M == j); }
      A.space[i][j] = tmp;
    }
  }

  cout << power(K, A, E).space[0][0] << endl;
}
