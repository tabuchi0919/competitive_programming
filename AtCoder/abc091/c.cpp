#include <algorithm>
#include <deque>
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
  int N;
  cin >> N;
  vector<pair<pair<int, int>, bool>> red(N), blue(N);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    red[i] = {make_pair(b, a), false};
  }
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    blue[i] = {make_pair(a, b), false};
  }
  sort(rALL(red));
  sort(ALL(blue));

  int ans = 0;

  REP(i, N) {
    REP(j, N) {
      if(blue[i].first.first > red[j].first.second &&
         blue[i].first.second > red[j].first.first && (!red[j].second)) {
        red[j].second = true;
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}
