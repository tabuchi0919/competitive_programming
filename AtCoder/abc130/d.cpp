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
  ll N, K, ans = 0ll;
  cin >> N >> K;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll right = 0ll;
  ll sum = 0ll;
  for(int left = 0; left < N; left++) {
    while(right < N && sum + a[right] < K) {
      sum += a[right];
      right++;
    }
    ans += N - right;
    if(right == left) {
      right++;
    } else {
      sum -= a[left];
    }
  }
  cout << ans << endl;
}
