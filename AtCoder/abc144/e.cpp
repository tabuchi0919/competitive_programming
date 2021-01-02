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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), F(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> F[i];
  sort(ALL(A));
  sort(rALL(F));

  ll ok = INFLL, ng = -1;
  while(ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    ll tmpk = 0ll;
    REP(i, N) {
      if(A[i] > mid / F[i]) {
        tmpk += A[i] - mid / F[i];
      }
    }
    if(tmpk <= K) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
}
