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

struct UnionFind {
  vector<ll> par;

  UnionFind(ll n) : par(n, -1) {}
  void init(ll n) { par.assign(n, -1); }

  ll root(ll x) {
    if(par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(ll x, ll y) { return root(x) == root(y); }

  bool merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x == y)
      return false;
    if(par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  ll size(ll x) { return -par[root(x)]; }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  vector<pair<ll, ll>> X(N), Y(N);
  for(ll i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    X[i] = make_pair(x, i);
    Y[i] = make_pair(y, i);
  }
  map<ll, pair<set<ll>, set<ll>>> mp;
  sort(ALL(X));
  sort(ALL(Y));

  UnionFind uf(N);

  for(ll i = 0; i < N - 1; i++) {
    if(X[i].first == X[i + 1].first) {
      uf.merge(X[i].second, X[i + 1].second);
    }
    if(Y[i].first == Y[i + 1].first) {
      uf.merge(Y[i].second, Y[i + 1].second);
    }
  }
  for(ll i = 0; i < N; i++) {
    mp[uf.root(X[i].second)].first.insert(X[i].first);
    mp[uf.root(Y[i].second)].second.insert(Y[i].first);
  }
  ll ans = 0ll;
  for(auto e : mp) {
    ans += 1ll * e.second.first.size() * e.second.second.size();
  }
  cout << ans - N << endl;
}
