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
  vector<vector<pair<int, bool>>> xy(N);
  REP(i, N) {
    int A;
    cin >> A;
    REP(j, A) {
      int x, y;
      cin >> x >> y;
      x--;
      xy[i].emplace_back(x, y);
    }
  }
  int ans = 0;
  for(int bit = 0; bit < (1 << N); ++bit) {
    vector<int> S;
    bool flag = true;
    int cnt = 0;
    vector<bool> honest(N);
    REP(i, N) {
      if(bit & (1 << i))
        honest[i] = true;
    }
    REP(i, N) {
      if(honest[i]) {
        cnt++;
        for(auto p : xy[i]) {
          if(honest[p.first] != p.second) {
            flag = false;
          };
        }
      }
    }

    if(flag)
      ans = max(ans, cnt);
  }
  cout << ans << endl;
}
