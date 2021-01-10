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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<long double> L(N);
  REP(i, N) cin >> L[i];
  ll K;
  cin >> K;
  long double high = 10000000000000000, low = 0;
  long double mid;

  REP(loop, 200) {
    ll cnt = 0;
    mid = (high + low) / 2.0;
    REP(i, N) { cnt += ll(L[i] / mid); }
    if(cnt >= K) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << setprecision(15) << mid << endl;
}
