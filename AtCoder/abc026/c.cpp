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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N - 1), salaries(N);
  vector<vector<int>> subs(N, vector<int>());

  REP(i, N - 1) {
    cin >> A[i];
    A[i]--;
    subs[A[i]].push_back(i + 1);
  }

  for(int i = N - 1; i >= 0; i--) {
    int ma = 0, mi = INF;
    auto sub = subs[i];
    for(auto e : sub) {
      mi = min(salaries[e], mi);
      ma = max(salaries[e], ma);
    }
    if(mi == INF)
      mi = 0;
    salaries[i] = mi + ma + 1;
  }

  cout << salaries[0] << endl;
}
