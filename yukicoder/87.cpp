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
  ll N;
  cin >> N;
  ll day = 0, nokori = N - 2014, ans = 0, mul = nokori / 2800;
  ans += mul * 399;
  nokori %= 2800;
  REP(i, nokori) {
    int y = 2015 + i;
    if(y % 400 == 0)
      day += 366;
    else if(y % 100 == 0)
      day += 365;
    else if(y % 4 == 0)
      day += 366;
    else
      day += 365;
    if(day % 7 == 0)
      ans++;
  }
  cout << ans << endl;
}
