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

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void PERinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long PER(int n, int k) {
  if(n < k)
    return 0;
  if(n < 0 || k < 0)
    return 0;
  return fac[n] * finv[n - k] % MOD;
}

long long FAC(int n) { return fac[n]; }

using Graph = vector<vector<int>>;

ll ans;
int N, K;
Graph G;
vector<int> degrees;

void dfs(int v, int p) {
  if(p != -1) {
    if(degrees[v] == 1)
      return;
    ans *= PER(K - 2, degrees[v] - 1);
    ans %= MOD;
  } else {
    ans *= PER(K - 1, degrees[v]);
    ans %= MOD;
  }
  for(auto nv : G[v]) {
    if(nv == p)
      continue;
    dfs(nv, v);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  PERinit();
  cin >> N >> K;
  ans = K;
  G.assign(N, vector<int>());
  degrees.assign(N, 0);
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
    degrees[a]++;
    degrees[b]++;
  }
  dfs(0, -1);
  cout << ans << endl;
}
