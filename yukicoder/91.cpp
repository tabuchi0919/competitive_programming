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
  int R, G, B;
  cin >> R >> G >> B;

  int ok = 0, ng = 100000000;
  while(ng - ok > 1) {
    int mid = (ok + ng) / 2;

    int tmp = 0;
    if(R - mid >= 0) {
      tmp += (R - mid) / 2;
    } else {
      tmp += (R - mid);
    }
    if(G - mid >= 0) {
      tmp += (G - mid) / 2;
    } else {
      tmp += (G - mid);
    }
    if(B - mid >= 0) {
      tmp += (B - mid) / 2;
    } else {
      tmp += (B - mid);
    }
    if(tmp >= 0) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
}
