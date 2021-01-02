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
  vector<int> a(N);
  REP(i, N) { cin >> a[i]; }
  int mi = *min_element(ALL(a)), ma = *max_element(ALL(a));
  int mii = min_element(ALL(a)) - a.begin() + 1,
      mai = max_element(ALL(a)) - a.begin() + 1;
  if(mi < 0 && ma > 0) {
    cout << 2 * N - 1 << endl;
    if(abs(mi) >= ma) {
      REP(i, N) { cout << mii << " " << i + 1 << endl; }
    } else {
      REP(i, N) { cout << mai << " " << i + 1 << endl; }
    }
  } else {
    cout << N - 1 << endl;
  }

  //すべて負のとき
  if(abs(mi) >= ma || ma <= 0) {
    REP(i, N - 1) { cout << N - i << " " << N - i - 1 << endl; }
  } else {
    REP(i, N - 1) { cout << i + 1 << " " << i + 2 << endl; }
  }
}
