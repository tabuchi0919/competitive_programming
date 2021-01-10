#include <algorithm>
#include <cassert>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

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
  ll N, Q;
  string S;
  cin >> N >> S;
  vector<ll> A(N), sum1(N + 1), sum2(N + 1);
  REP(i, N) { cin >> A[i]; }
  REP(i, N) {
    sum1[i + 1] += sum1[i] + A[i];
    if(S[i] == 'E') {
      sum2[i + 1] += sum2[i] + 1;
    } else {
      sum2[i + 1] += sum2[i];
    }
  }
  vector<ll> cnt(N + 1, INFLL);
  REP(i, N + 1) {
    REP(j, i) { chmin(cnt[sum2[i] - sum2[j]], sum1[i] - sum1[j]); }
  }
  cin >> Q;
  REP(i, Q) {
    ll tmp;
    cin >> tmp;
    cout << max(0ll, upper_bound(ALL(cnt), tmp) - cnt.begin() - 1ll) << endl;
  }
}
