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
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  long double ans1 = W / 2.0 * H;
  int ans2 = 0;
  if(2 * x == W && 2 * y == H)
    ans2 = 1;
  cout << setprecision(12) << ans1 << " " << ans2 << endl;
}
