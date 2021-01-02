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
  string S, T;
  cin >> S >> T;
  int n = S.length();
  bool ans = true;
  REP(i, n) {
    if((S[i] != T[i] && S[i] != 'a' && S[i] != 't' && S[i] != 'c' &&
        S[i] != 'o' && S[i] != 'd' && S[i] != 'e' && S[i] != 'r' &&
        T[i] != 'a' && T[i] != 't' && T[i] != 'c' && T[i] != 'o' &&
        T[i] != 'd' && T[i] != 'e' && T[i] != 'r') ||
       (S[i] != T[i] && S[i] != '@' && T[i] != '@'))
      ans = false;
  }
  if(ans) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }
}
