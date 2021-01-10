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
  string S;
  cin >> S;
  int ans = 0, now = 0;
  char last = '*';
  REP(i, S.length()) {
    if(S[i] == '*' || S[i] == '+') {
      if(last == '*') {
        ans += now;
        now = 0;
      } else {
        ans *= now;
        now = 0;
      }
      last = S[i];
    } else {
      int n = S[i] - '0';
      now *= 10;
      now += n;
    }
  }
  if(last == '*') {
    ans += now;
    now = 0;
  } else {
    ans *= now;
    now = 0;
  }
  cout << ans << endl;
}
