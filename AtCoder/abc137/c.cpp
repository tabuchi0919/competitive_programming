#include <algorithm>
#include <deque>
#include <functional>
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
#include <unordered_map>
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
  int N;
  cin >> N;
  vector<string> S(N);
  unordered_map<string, ll> mp;
  REP(i, N) {
    cin >> S[i];
    sort(ALL(S[i]));
    mp[S[i]]++;
  }

  ll ans = 0ll;
  for(auto e : mp) {
    ans += (e.second * (e.second - 1)) / 2;
  }
  cout << ans << endl;
}
