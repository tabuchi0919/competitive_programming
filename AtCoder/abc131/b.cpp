#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, L, diff = INF, ans, sum;
  cin >> N >> L;
  vector<int> taste(N);
  for(int i = 0; i < N; i++)
    taste[i] = L + i;

  sum = accumulate(ALL(taste), 0);
  for(int i = 0; i < N; i++) {
    int sum2 = 0;
    for(int j = 0; j < N; j++) {
      if(i == j)
        continue;
      sum2 += taste[j];
    }
    if(abs(sum2 - sum) < diff) {
      diff = abs(sum2 - sum);
      ans = sum2;
    }
  }
  cout << ans << endl;
}
