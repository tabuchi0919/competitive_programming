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
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N), sum(N + 1);
  map<ll, ll> mp;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum[i + 1] = sum[i] + A[i];
    mp[sum[i + 1] % M]++;
  }
  mp[0]++;
  ll ans = 0ll;
  for(auto e : mp) {
    ll n = e.second;
    ans += n * (n - 1) / 2;
  }
  cout << ans << endl;
}
