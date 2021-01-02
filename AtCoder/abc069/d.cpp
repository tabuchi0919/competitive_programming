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
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  vector<int> tmp;
  REP(i, N) {
    REP(j, A[i]) { tmp.push_back(i + 1); }
  }
  vector<vector<int>> ans(H, vector<int>(W, 0));
  REP(i, H) {
    REP(j, W) { ans[i][j] = tmp[i * W + j]; }
    if(i % 2) {
      reverse(ALL(ans[i]));
    }
  }
  REP(i, H) {
    REP(j, W - 1) { cout << ans[i][j] << " "; }
    cout << ans[i][W - 1] << endl;
  }
}
