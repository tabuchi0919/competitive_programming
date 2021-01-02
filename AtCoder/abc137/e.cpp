#include <algorithm>
#include <deque>
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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, P;
  cin >> N >> M >> P;
  vector<ll> a(M), b(M), c(M), dist(N, INFLL);
  REP(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    c[i] = -c[i] + P;
  }

  dist[0] = 0;

  REP(loop, N - 1) {
    REP(i, M) {
      if(dist[a[i]] != INFLL) {
        dist[b[i]] = min(dist[b[i]], dist[a[i]] + c[i]);
      }
    }
  }

  ll ans = -dist[N - 1];

  vector<bool> negative(N, false);

  REP(loop, N) {
    REP(i, M) {
      if(dist[a[i]] == INFLL)
        continue;
      if(dist[b[i]] > dist[a[i]] + c[i]) {
        dist[b[i]] = dist[a[i]] + c[i];
        negative[b[i]] = true;
      }

      if(negative[a[i]]) {
        negative[b[i]] = true;
      }
    }
  }

  if(negative[N - 1]) {
    cout << -1 << endl;
  } else {
    cout << max(ans, 0ll) << endl;
  }
}
