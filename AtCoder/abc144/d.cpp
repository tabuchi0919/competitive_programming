#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
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

const double PI = 3.14159265358979323846;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int a, b, x;
  cin >> a >> b >> x;
  double aa = a;
  double bb = b;
  double xx = x;
  if(2 * x <= a * a * b) {
    cout << setprecision(12) << 90 - atan(2.0 * xx / aa / bb / bb) * 180 / PI
         << endl;
  } else {
    double l = 2.0 * bb - 2.0 * xx / aa / aa;
    cout << setprecision(12) << atan(l / aa) * 180 / PI << endl;
  }
}
