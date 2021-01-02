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
  int H, W, D;
  cin >> H >> W >> D;
  vector<pair<int, int>> A(H * W);
  REP(i, H * W) {
    int a;
    cin >> a;
    a--;
    A[a] = make_pair(i - i / W * W, i / W);
  }

  vector<vector<int>> sum(D);
  REP(i, D) {
    sum[i].push_back(0);
    int now = i;
    while(now + D < H * W) {
      int last = sum[i].back();
      int diff = abs(A[now + D].first - A[now].first) +
                 abs(A[now + D].second - A[now].second);
      sum[i].push_back(last + diff);
      now += D;
    }
  }

  int Q;
  cin >> Q;
  REP(i, Q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int mo = l % D;
    cout << sum[mo][r / D] - sum[mo][l / D] << endl;
  }
}
