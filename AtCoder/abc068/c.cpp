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
  vector<pair<bool, bool>> canReach(N);
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if(a == 0) {
      canReach[b].first = true;
    }
    if(b == 0) {
      canReach[a].first = true;
    }
    if(a == N - 1) {
      canReach[b].second = true;
    }
    if(b == N - 1) {
      canReach[a].second = true;
    }
  }
  bool flag = false;
  for(int i = 0; i < N; i++) {
    if(canReach[i].first && canReach[i].second)
      flag = true;
  }
  if(flag) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
