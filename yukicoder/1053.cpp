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
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
    A[i]--;
  }
  A.erase(unique(A.begin(), A.end()), A.end());
  N = A.size();
  //隣り合っていないものがあった時点で駄目、ただし最初と最後のやつだけは合わせられる
  bool flag = true;
  int ans = 0;
  vector<int> v(100010, -1);
  REP(i, N - 1) {
    int last = v[A[i]];
    v[A[i]] = i;
    if(last != -1 && i - last != 1) {
      flag = false;
    }
  }
  int last = v[A[N - 1]];
  if(last != -1 && last != N - 2 && last != 0) {
    flag = false;
  }
  if(last == 0) {
    ans++;
  }

  cout << (flag ? ans : -1) << endl;
}
