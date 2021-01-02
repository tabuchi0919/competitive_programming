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
  int N, C;
  cin >> N >> C;
  vector<tuple<int, int, int>> stc;
  REP(i, N) {
    int s, t, c;
    cin >> s >> t >> c;
    stc.emplace_back(s, t, c);
  }
  sort(ALL(stc));
  vector<pair<int, int>> recorders(C, {0, -1});
  REP(i, N) {
    int s = get<0>(stc[i]);
    int t = get<1>(stc[i]);
    int c = get<2>(stc[i]);
    bool ren = false;
    REP(j, C) {
      if(c == recorders[j].first && s == recorders[j].second) {
        ren = true;
        recorders[j] = make_pair(c, t);
        break;
      }
    }
    if(ren)
      continue;
    REP(j, C) {
      if(recorders[j].second < s) {
        recorders[j] = make_pair(c, t);
        break;
      }
    }
  }
  int ans = 0;
  REP(i, C) ans += (recorders[i].second != -1);
  cout << ans << endl;
}
