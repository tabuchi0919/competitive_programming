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

int ans = 0;

void dfs(int i, int now, int &N, vector<int> &A, vector<bool> &used) {
  if(i == N) {
    ans = max(ans, now);
  } else {
    for(int j = 0; j < N; j++) {
      if(!used[j]) {
        used[j] = 1;
        for(int k = j + 1; k < N; k++) {
          if(!used[k]) {
            used[k] = 1;
            dfs(i + 2, now ^ (A[j] + A[k]), N, A, used);
            used[k] = 0;
          }
        }
        used[j] = 0;
        break;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  vector<bool> used(N);
  REP(i, N) cin >> A[i];
  dfs(0, 0, N, A, used);
  cout << ans << endl;
}
