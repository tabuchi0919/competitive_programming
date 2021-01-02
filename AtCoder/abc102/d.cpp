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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> A(N), sum(N + 1);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum[i + 1] = sum[i] + A[i];
  }
  ll ans = INFLL;
  ll a, b, c, d;
  int left = 0, right = 2;
  for(int i = 1; i < N - 1; i++) {
    while(left <= i - 1 && (sum[i + 1] - sum[left + 1] >= sum[left + 1])) {
      left++;
    }
    if(abs(2 * sum[left] - sum[i + 1]) < abs(2 * sum[left + 1] - sum[i + 1])) {
      a = sum[left];
      b = sum[i + 1] - sum[left];
      left--;
    } else {
      a = sum[left + 1];
      b = sum[i + 1] - sum[left + 1];
    }

    while(right <= N - 2 &&
          (sum[N] - sum[right + 1] >= sum[right + 1] - sum[i + 1])) {
      right++;
    }

    if(abs(sum[N] + sum[i + 1] - 2 * sum[right]) <
       abs(sum[N] + sum[i + 1] - 2 * sum[right + 1])) {
      c = sum[right] - sum[i + 1];
      d = sum[N] - sum[right];
      right--;
    } else {
      c = sum[right + 1] - sum[i + 1];
      d = sum[N] - sum[right + 1];
    }
    ans = min(ans, max({a, b, c, d}) - min({a, b, c, d}));
  }
  cout << ans << endl;
}
