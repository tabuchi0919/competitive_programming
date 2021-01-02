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
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, ans = 0ll;
  cin >> N;
  vector<ll> A(N + 1), B(N);
  REP(i, N + 1) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) {
    if(A[i] >= B[i]) {
      ans += B[i];
    } else if(A[i] + A[i + 1] <= B[i]) {
      ans += A[i] + A[i + 1];
      A[i + 1] = 0;
    } else {
      ans += B[i];
      A[i + 1] -= B[i] - A[i];
    }
  }
  cout << ans << endl;
}
