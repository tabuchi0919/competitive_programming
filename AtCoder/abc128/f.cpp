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
  vector<ll> s(N);
  REP(i, N) cin >> s[i];

  ll ans = 0;
  FOR(C, 1, N) {
    ll sum = 0ll;
    if((N - 1) % C == 0) {
      for(int i = 0; i * C < N - 1 - i * C; i++) {
        sum += s[N - 1 - i * C];
        sum += s[i * C];
        ans = max(ans, sum);
      }
    } else {
      for(int i = 0; i * C + C < N - 1; i++) {
        sum += s[N - 1 - i * C];
        sum += s[i * C];
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
}
