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
  int N;
  cin >> N;
  vector<ll> A(2 * N);
  REP(i, 2 * N) cin >> A[i];
  vector<ll> sumodd(N + 1), sumeven(N + 1);
  REP(i, N) {
    sumodd[i + 1] = sumodd[i] + A[i * 2];
    sumeven[i + 1] = sumeven[i] + A[i * 2 + 1];
  }
  ll ans = -INFLL;
  REP(i, N + 1) {
    ll homu = 0, tem = 0;
    //ひだりから2*i番目まではほむらが常に左を取る、それ移行はほむらが右を取る
    homu += sumodd[i];
    tem += sumeven[i];
    homu += sumeven[N] - sumeven[i];
    tem += sumodd[N] - sumodd[i];
    chmax(ans, homu - tem);
  }
  cout << ans << endl;
}
