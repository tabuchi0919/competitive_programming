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
  int N, cnt = 0, pp, qq;
  cin >> N;
  vector<int> nums(N), p(N), q(N);

  REP(i, N) { nums[i] = i + 1; }

  REP(i, N) {
    int tmp;
    cin >> tmp;
    p[i] = tmp;
  }
  REP(i, N) {
    int tmp;
    cin >> tmp;
    q[i] = tmp;
  }

  do {
    if(equal(ALL(nums), p.begin()))
      pp = cnt;
    if(equal(ALL(nums), q.begin()))
      qq = cnt;
    cnt++;
  } while(std::next_permutation(ALL(nums)));
  cout << abs(pp - qq) << endl;
}
