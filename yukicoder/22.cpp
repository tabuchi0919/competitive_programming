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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, K;
  string S;
  cin >> N >> K >> S;
  K--;
  vector<int> sum(N);
  sum[0] = 1;
  REP(i, N - 1) { sum[i + 1] = sum[i] + (S[i + 1] == '(' ? 1 : -1); }
  int i = K, ans;
  if(S[K] == '(') {
    while(true) {
      if(sum[K] - 1 == sum[i] && S[i] == ')') {
        ans = i + 1;
        break;
      }
      i++;
    }
  } else {
    while(true) {
      if(sum[K] + 1 == sum[i] && S[i] == '(') {
        ans = i + 1;
        break;
      }
      i--;
    }
  }
  cout << ans << endl;
}
