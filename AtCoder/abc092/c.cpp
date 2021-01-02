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
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> a(N + 2);
  a[0] = 0;
  REP(i, N) cin >> a[i + 1];
  a[N + 1] = 0;
  int sum = 0;
  for(int i = 1; i <= N + 1; i++) {
    sum += abs(a[i] - a[i - 1]);
  }
  for(int i = 1; i <= N; i++) {
    if((a[i - 1] <= a[i] && a[i] <= a[i + 1]) ||
       (a[i - 1] >= a[i] && a[i] >= a[i + 1])) {
      cout << sum << endl;
    } else {
      cout << sum - 2 * min(abs(a[i] - a[i - 1]), abs(a[i + 1] - a[i])) << endl;
    }
  }
}
