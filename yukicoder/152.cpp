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

int gcd(int a, int b) {
  if(a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int L, ans = 0;
  cin >> L;
  FOR(i, 1, 4000) {
    FOR(j, 1, i) {
      if(gcd(i, j) == 1 && abs(j - i) % 2 == 1) {
        if((2 * i * i + 2 * i * j) * 4 <= L)
          ans++;
      }
    }
  }
  cout << ans << endl;
}
