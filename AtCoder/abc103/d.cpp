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
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> YX(M);
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    YX[i] = {y, x};
  }
  sort(ALL(YX));
  int last = -1, ans = 0;
  for(int i = 0; i < M; i++) {
    int x, y;
    x = YX[i].second;
    y = YX[i].first;
    if(x > last) {
      ans++;
      last = y - 1;
    }
  }
  cout << ans << endl;
}
