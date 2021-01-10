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
  ll A, B;
  cin >> A >> B;
  ll ans = -1;
  for(int i = 1; i * i <= A + B; i++) {
    if((A + B) % i == 0) {
      ll c1 = i, c2 = (A + B) / i;
      if((B + c1) % A == 0 && (A + c1) % B == 0 && c1 != A && c1 != B) {
        ans = c1;
      }
      if((B + c2) % A == 0 && (A + c2) % B == 0 && c2 != A && c2 != B) {
        ans = c2;
      }
    }
  }
  cout << ans << endl;
}
