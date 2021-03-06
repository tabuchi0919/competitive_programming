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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10, 0)), P(N, vector<int>(11, 0));
  REP(i, N) { REP(j, 10) cin >> F[i][j]; }
  REP(i, N) { REP(j, 11) cin >> P[i][j]; }
  int ans = -INF;
  for(int mask = 1; mask < (1 << 10); mask++) {
    int sum = 0;
    REP(i, N) {
      int cnt = 0;
      REP(j, 10) {
        if((mask & (1 << j)) && F[i][j])
          cnt++;
      }
      sum += P[i][cnt];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
}
