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
  ll Q, L, size = 0;
  cin >> Q >> L;
  vector<pair<ll, ll>> st;
  REP(qq, Q) {
    string q;
    cin >> q;
    if(q == "Push") {
      ll N, M;
      cin >> N >> M;
      st.emplace_back(N, M);
      size += N;
      if(size > L) {
        cout << "FULL" << endl;
        break;
      }
    }
    if(q == "Pop") {
      ll N;
      cin >> N;
      size -= N;
      if(size < 0) {
        cout << "EMPTY" << endl;
        break;
      }
      while(true) {
        auto [n, m] = st.back();
        if(n <= N) {
          N -= n;
          st.pop_back();
        } else {
          st.pop_back();
          st.emplace_back(n - N, m);
          N = 0;
        }
        if(N == 0)
          break;
      }
    }
    if(q == "Top") {
      if(size == 0) {
        cout << "EMPTY" << endl;
        break;
      }
      cout << st.back().second << endl;
    }
    if(q == "Size") {
      cout << size << endl;
    }
    if(qq == Q - 1) {
      cout << "SAFE" << endl;
    }
  }
}
