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
  int N;
  cin >> N;
  vector<vector<int>> edges(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  queue<int> q;
  q.push(0);
  q.push(N - 1);
  vector<int> field(N, 0);
  field[0] = 1, field[N - 1] = -1;

  while(!q.empty()) {
    int now = q.front();
    q.pop();
    for(const auto &next : edges[now]) {
      if(field[next] == 0) {
        field[next] = field[now];
        q.push(next);
      }
    }
  }

  if(accumulate(ALL(field), 0) > 0) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}
