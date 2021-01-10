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
  int D;
  cin >> D;
  vector<int> a(D + 1);
  REP(i, D + 1) cin >> a[i];
  for(int i = D; i > 2; i--) {
    a[i - 2] += a[i];
    a[i] = 0;
  }
  if(a[2] == 0 && a[1] == 0) {
    cout << 0 << endl;
    cout << a[0] << endl;
  } else if(a[2] == 0) {
    cout << 1 << endl;
    cout << a[0] << " " << a[1] << endl;
  } else {
    cout << 2 << endl;
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
  }
}
