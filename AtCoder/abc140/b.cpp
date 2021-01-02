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
  int N, ans = 0;
  cin >> N;
  vector<int> A(N), B(N), C(N - 1);
  REP(i, N) cin >> A[i];
  REP(i, N) {
    int b;
    cin >> b;
    ans += b;
  }
  REP(i, N - 1) cin >> C[i];

  REP(i, N - 1) {
    if(A[i] + 1 == A[i + 1]) {
      ans += C[A[i] - 1];
    }
  }

  cout << ans << endl;
}
