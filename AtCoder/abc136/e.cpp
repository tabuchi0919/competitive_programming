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
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll sum = accumulate(ALL(A), 0ll);
  vector<ll> factors;
  for(int i = 1; i * i <= sum; i++) {
    if(sum % i == 0) {
      factors.push_back(i);
      if(i != sum / i)
        factors.push_back(sum / i);
    }
  }
  sort(ALL(factors));
  sort(ALL(A));
  vector<ll> ans;
  for(auto e : factors) {
    if(e == 1) {
      ans.push_back(1);
      continue;
    }
    vector<ll> tmp(N);
    REP(i, N) tmp[i] = A[i] % e;
    sort(ALL(tmp));
    ll tmpsum = accumulate(ALL(tmp), 0ll);
    ll ma = N - tmpsum / e;
    ll cnt = 0ll;
    REP(i, ma) { cnt += tmp[i]; }
    if(cnt <= K)
      ans.push_back(e);
  }
  cout << ans.back() << endl;
}
