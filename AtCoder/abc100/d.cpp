#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> d = {{1, 1, 1},   {1, 1, -1},  {1, -1, 1},  {-1, 1, 1},
                           {1, -1, -1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
  vector<ll> x(N), y(N), z(N), sum(N);
  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }

  ll ans = 0ll;
  for(auto e : d) {
    for(int i = 0; i < N; i++) {
      sum[i] = e[0] * x[i] + e[1] * y[i] + e[2] * z[i];
    }
    sort(rALL(sum));
    ans = max(ans, accumulate(sum.begin(), sum.begin() + M, 0ll));
  }

  cout << ans << endl;
}
