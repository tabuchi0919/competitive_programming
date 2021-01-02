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
  string s, t;
  cin >> s >> t;
  bool ans = true;
  REP(i, s.length()) {
    if(s[i] == '@') {
      if(t[i] != 'a' && t[i] != 't' && t[i] != 'c' && t[i] != 'o' &&
         t[i] != 'd' && t[i] != 'e' && t[i] != 'r' && t[i] != '@') {
        ans = false;
      }
    } else if(t[i] == '@') {
      if(s[i] != 'a' && s[i] != 't' && s[i] != 'c' && s[i] != 'o' &&
         s[i] != 'd' && s[i] != 'e' && s[i] != 'r' && s[i] != '@') {
        ans = false;
      }
    } else {
      if(s[i] != t[i]) {
        ans = false;
      }
    }
  }
  if(ans) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }
}
