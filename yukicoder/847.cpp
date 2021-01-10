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

void dfs(ll i, ll &ans, ll &d, ll &K, ll &M, vector<pair<ll, ll>> fac) {
  if(i == fac.size()) {
    ans++;
    return;
  }
  ll p = fac[i].first, e = fac[i].second;
  ll pp = 1;
  for(int j = 0; j <= K * e; j++) {
    d *= pp;
    dfs(i + 1, ans, d, K, M, fac);
    d /= pp;
    pp *= p;
    if(d * pp > M)
      break;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, K, M;
  cin >> N >> K >> M;
  vector<pair<ll, ll>> fac;
  if(N == 1) {
    cout << 1 << endl;
  } else {
    for(ll i = 2; i * i <= N; i++) {
      if(N % i == 0) {
        ll e = 0;
        while(N % i == 0) {
          N /= i;
          e++;
        }
        fac.push_back(pair<ll, ll>(i, e));
      }
    }
    if(N > 1)
      fac.push_back(pair<ll, ll>(N, 1));
    ll d = 1, ans = 0;
    dfs(0, ans, d, K, M, fac);
    cout << ans << endl;
  }
}
