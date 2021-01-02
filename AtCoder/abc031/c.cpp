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
  int N;
  cin >> N;
  vector<int> a(N), ans(N);
  REP(i, N) cin >> a[i];
  REP(i, N) {
    int aoki = -INF;
    REP(j, N) {
      int tmptaka = 0, tmpao = 0;
      if(i == j)
        continue;
      int mi = min(i, j), ma = max(i, j);
      FOR(k, mi, ma + 1) {
        if((k - mi) % 2 == 0) {
          tmptaka += a[k];
        } else {
          tmpao += a[k];
        }
      }
      if(tmpao > aoki) {
        aoki = tmpao;
        ans[i] = tmptaka;
      }
    }
  }
  cout << *max_element(ans.begin(), ans.end()) << endl;
}
