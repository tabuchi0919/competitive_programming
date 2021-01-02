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
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) cin >> C[i];
  sort(ALL(A));
  sort(ALL(B));
  sort(ALL(C));
  ll ans = 0;

  REP(i, N) {
    ll a = lower_bound(ALL(A), B[i]) - A.begin();
    ll c = C.end() - upper_bound(ALL(C), B[i]);
    ans += a * c;
  }
  cout << ans << endl;
}
