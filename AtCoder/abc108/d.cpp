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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int L;
  cin >> L;
  int r = 0, tmp = 1;
  while(2 * tmp <= L) {
    tmp *= 2;
    r++;
  }
  vector<tuple<int, int, int>> ans;
  REP(i, r) {
    ans.emplace_back(i + 1, i + 2, 1 << i);
    ans.emplace_back(i + 1, i + 2, 0);
  }

  for(int i = r; i >= 1; i--) {
    if(L - (1 << (i - 1)) >= (1 << r)) {
      ans.emplace_back(i, r + 1, L - (1 << (i - 1)));
      L -= (1 << (i - 1));
    }
  }

  cout << r + 1 << ' ' << ans.size() << endl;
  for(auto e : ans) {
    cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << endl;
  }
}
