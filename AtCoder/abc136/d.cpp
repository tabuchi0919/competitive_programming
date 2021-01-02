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
  string S;
  cin >> S;
  int N = S.length();
  int left = 0, right = 0, tmp;
  vector<int> ans(N, 0);
  REP(i, N) {
    if(S[i] == 'R' && S[i + 1] == 'L') {
      tmp = i;
    }
    if(i == N - 1 || (S[i] == 'L' && S[i + 1] == 'R')) {
      right = i;
      if((right - left + 1) % 2 == 1) {
        if((tmp - left) % 2 == 0) {
          ans[tmp]++;
        } else {
          ans[tmp + 1]++;
        }
      }
      ans[tmp] += (right - left + 1) / 2;
      ans[tmp + 1] += (right - left + 1) / 2;
      left = i + 1;
    }
  }
  REP(i, N - 1) { cout << ans[i] << " "; }
  cout << ans[N - 1] << endl;
}
