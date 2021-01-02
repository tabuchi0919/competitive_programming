#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, ans = 0;
  cin >> N;
  vector<int> A(N);
  map<int, int> mp;
  REP(i, N) {
    cin >> A[i];
    if(A[i] > 100000) {
      ans++;
    } else {
      mp[A[i]]++;
    }
  }
  for(auto e : mp) {
    if(e.first < e.second)
      ans += e.second - e.first;
    if(e.first > e.second)
      ans += e.second;
  }
  cout << ans << endl;
}
