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
  ll P, Q, R, A, B, C;
  cin >> P >> Q >> R >> A >> B >> C;
  B = A + B;
  C = B + C;
  ll ma, mi;
  ma = min({A * P, B * Q, C * R});
  mi = max({A * P - P, B * Q - Q, C * R - R});
  if(mi + 1 > ma) {
    cout << -1 << endl;
  } else {
    cout << mi + 1 << " " << ma << endl;
  }
}
