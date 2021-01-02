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
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int>> stx(n);
  for(int i = 0; i < n; i++) {
    cin >> get<1>(stx[i]) >> get<2>(stx[i]) >> get<0>(stx[i]);
  }
  sort(ALL(stx));
  set<pair<int, int>> d;
  for(int i = 0; i < q; i++) {
    int x;
    cin >> x;
    d.emplace(x, i);
  }
  vector<ll> ans(q, -1);
  for(int i = 0; i < n; i++) {
    auto first = d.lower_bound(make_pair(get<1>(stx[i]) - get<0>(stx[i]), 0));
    auto last =
        d.upper_bound(make_pair(get<2>(stx[i]) - get<0>(stx[i]) - 1, q));

    for(auto it = first; it != last; it++) {
      ans[(*it).second] = get<0>(stx[i]);
    }
    d.erase(first, last);
  }
  for(int i = 0; i < q; i++)
    cout << ans[i] << "\n";
}
