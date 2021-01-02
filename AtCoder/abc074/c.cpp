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
  unordered_set<int> xs, ys;
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  REP(i, f) {
    REP(j, f) {
      if(100 * a * i + 100 * a * j <= f) {
        xs.insert(100 * a * i + 100 * a * j);
      }
    }
  }
  REP(i, f) {
    REP(j, f) {
      if(c * i + d * j <= f) {
        ys.insert(c * i + d * j);
      }
    }
  }
  xs.erase(0);
  int suger = 0, water = 0;
  double conc = 0;
  for(auto x : xs) {
    for(auto y : ys) {
      if(x + y <= f && 100 * y <= x * e) {
        double tmp = double(y) / double(x);
        if(tmp >= conc) {
          water = x;
          suger = y;
          conc = tmp;
        }
      }
    }
  }
  cout << water + suger << ' ' << suger << endl;
}
