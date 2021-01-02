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
  int A, B, C, X, Y, ans = INF;
  cin >> A >> B >> C >> X >> Y;
  for(int i = 0; i <= 2 * max(X, Y); i += 2) {
    ans = min(ans, max(0, X - i / 2) * A + max(0, Y - i / 2) * B + i * C);
  }
  cout << ans << endl;
}
