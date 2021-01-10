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
  ll W, H, N;
  cin >> W >> H >> N;
  vector<ll> S(N), K(N);
  REP(i, N) cin >> S[i] >> K[i];
  map<ll, int> mp1, mp2;
  REP(i, N) {
    mp1[S[i]]++;
    mp2[K[i]]++;
  }
  ll sc = 0, kc = 0;
  for(auto e : mp1) {
    sc++;
  }
  for(auto e : mp2) {
    kc++;
  }
  cout << sc * H + kc * W - sc * kc - N << endl;
}
