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
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> BA(N);
  set<int> times;
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    BA[i] = make_pair(-b, -a);
  }
  REP(i, M) times.insert(i);
  sort(ALL(BA));
  ll now = 0ll, ans = 0ll;
  for(auto e : BA) {
    int value = -e.first;
    int time = -e.second;
    auto it = times.lower_bound(time - 1);
    if(it != times.end()) {
      ans += value;
      times.erase(it);
    }
  }
  cout << ans << endl;
}
