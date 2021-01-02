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
const int MOD = 2019;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  map<int, int> mp;
  mp[0] = 1;
  int now = 0, N = S.length();
  vector<int> pows(N + 1);
  pows[0] = 1;
  REP(i, N) {
    pows[i + 1] = pows[i] * 10;
    pows[i + 1] %= MOD;
  }
  int ans = 0;
  REP(i, N) {
    now += ((S[N - i - 1] - '0') * pows[i]);
    now %= 2019;
    ans += mp[now];
    mp[now]++;
  }
  cout << ans << endl;
}
