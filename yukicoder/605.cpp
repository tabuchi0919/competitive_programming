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
  ll space[2][2];

  matrix operator*(const matrix &another) const {
    matrix ans;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        ans.space[i][j] = 0;
        for(int k = 0; k < 2; k++) {
          ans.space[i][j] += space[i][k] * another.space[k][j];
        }
        ans.space[i][j] %= MOD;
      }
    }
    return ans;
  }
};

const matrix E = {{{1, 0}, {0, 1}}};
const matrix A = {{{1, 1}, {1, 0}}};

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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  cout << power(n + 1).space[1][1] * power(n + 2).space[1][1] % MOD << endl;
}
