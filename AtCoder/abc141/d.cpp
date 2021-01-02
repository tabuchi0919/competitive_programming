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
  int N, M;
  cin >> N >> M;
  priority_queue<int> q;
  REP(i, N) {
    int tmp;
    cin >> tmp;
    q.push(tmp);
  }
  REP(i, M) {
    int ma = q.top();
    q.pop();
    q.push(ma / 2);
  }
  ll ans = 0ll;
  while(!q.empty()) {
    int tmp = q.top();
    ans += tmp;
    q.pop();
  }
  cout << ans << endl;
}
