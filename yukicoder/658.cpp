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
  int space[4][4];

  matrix operator*(const matrix &another) const {
    matrix ans;
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        ans.space[i][j] = 0;
        for(int k = 0; k < 4; k++) {
          ans.space[i][j] += space[i][k] * another.space[k][j];
        }
        ans.space[i][j] %= 17;
      }
    }
    return ans;
  }
};

const matrix A = {{{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};
const matrix E = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

matrix power(ll exponent) {
  if(exponent % 2) {
    return power(exponent - 1) * A;
  } else if(exponent) {
    matrix root_ans = power(exponent / 2);
    return root_ans * root_ans;
  } else {
    return E;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int Q;
  cin >> Q;
  matrix mat = {{{1, 1, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};

  REP(i, Q) {
    ll n;
    cin >> n;
    cout << power(n).space[3][3] << endl;
  }
}
