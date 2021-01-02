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
  string S;
  cin >> N >> S;
  for(int i = 0; i < N; i++) {
    map<char, pair<bool, bool>> mp;
    for(int j = 0; j < N; j++) {
      if(i <= j) {
        mp[S[j]].first = true;
      } else {
        mp[S[j]].second = true;
      }
    }
    int cnt = 0;
    for(auto e : mp) {
      cnt += e.second.first && e.second.second;
    }
    ans = max(cnt, ans);
  }
  cout << ans << endl;
}
