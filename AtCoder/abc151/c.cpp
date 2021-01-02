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
  int N, M;
  cin >> N >> M;
  vector<int> wa(N), ac(N);
  int ans = 0;
  REP(i, M) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if(s == "AC") {
      ac[p]++;
    } else {
      if(ac[p] == 0) {
        wa[p]++;
      }
    }
  }

  int accnt = 0, wacnt = 0;
  REP(i, N) {
    if(ac[i] == 0)
      continue;
    accnt++;
    wacnt += wa[i];
  }

  cout << accnt << ' ' << wacnt << endl;
}
