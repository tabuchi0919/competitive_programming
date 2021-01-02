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
  ll N, K, R, S, P, ans = 0;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  map<char, ll> mp;
  mp['r'] = P;
  mp['p'] = S;
  mp['s'] = R;
  REP(i, K) {
    //あまりがiのところでの
    ll tmp = 0;
    bool last_used = false;
    for(int j = i; j < N; j += K) {
      char t = T[j];
      if(last_used) {
        if(t == T[j - K]) {
          // ng
          last_used = false;
        } else {
          // ok
          last_used = true;
          tmp += mp[t];
        }
      } else {
        // 問答無用でおｋ
        last_used = true;
        tmp += mp[t];
      }
    }
    ans += tmp;
  }
  cout << ans << endl;
}
