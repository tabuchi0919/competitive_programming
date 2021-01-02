#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; --i)
#define srep(i, s, t) for(int i = (int)(s); i < (int)(t); ++i)
#define each(a, b) for(auto &(a) : (b))
#define all(v) (v).begin(), (v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define cmx(x, y) x = max(x, y)
#define cmn(x, y) x = min(x, y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout << #x << " = " << (x) << endl
#define spair(p) cout << #p << ": " << p.fi << " " << p.se << endl
#define sar(a, n)                                                              \
  cout << #a << ":";                                                           \
  rep(pachico, n) cout << " " << a[pachico];                                   \
  cout << endl
#define svec(v)                                                                \
  cout << #v << ":";                                                           \
  rep(pachico, v.size()) cout << " " << v[pachico];                            \
  cout << endl
#define svecp(v)                                                               \
  cout << #v << ":";                                                           \
  each(pachico, v) cout << " {" << pachico.first << ":" << pachico.second      \
                        << "}";                                                \
  cout << endl
#define sset(s)                                                                \
  cout << #s << ":";                                                           \
  each(pachico, s) cout << " " << pachico;                                     \
  cout << endl
#define smap(m)                                                                \
  cout << #m << ":";                                                           \
  each(pachico, m) cout << " {" << pachico.first << ":" << pachico.second      \
                        << "}";                                                \
  cout << endl

using namespace std;

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

template <typename T> class segtree {
private:
  int n, sz;
  vector<pair<T, int>> node;

public:
  void resize(vector<T> &v) {
    sz = (int)v.size();
    n = 1;
    while(n < sz) {
      n *= 2;
    }
    node.resize(2 * n);
    for(int i = 0; i < sz; i++) {
      node[i + n] = make_pair(v[i], i);
    }
    for(int i = n - 1; i >= 1; i--) {
      node[i] = min(node[2 * i], node[2 * i + 1]);
    }
  }
  void update(int k, T a) {
    node[k += n] = make_pair(a, k);
    while(k >>= 1) {
      node[k] = min(node[2 * k], node[2 * k + 1]);
    }
  }
  pair<T, int> query(int a, int b, int k = 0, int l = 0, int r = -1) {
    pair<T, int> res1 = make_pair(numeric_limits<T>::max(), -1);
    pair<T, int> res2 = make_pair(numeric_limits<T>::max(), -1);
    a += n, b += n;
    while(a != b) {
      if(a % 2)
        cmn(res1, node[a++]);
      if(b % 2)
        cmn(res2, node[--b]);
      a >>= 1, b >>= 1;
    }
    return min(res1, res2);
  }
};

class LCA {
public:
  int V;
  vector<vector<int>> G;
  vector<int> ord, depth, id;
  segtree<int> st;
  LCA(int node_size) : V(node_size), G(V), depth(V), id(V, -1) {}
  void add_edge(int from, int to) {
    G[from].push_back(to), G[to].push_back(from);
  }
  void dfs(int u, int p, int k) {
    id[u] = (int)ord.size();
    ord.push_back(u);
    depth[u] = k;
    for(int v : G[u]) {
      if(v != p) {
        dfs(v, u, k + 1);
        ord.push_back(u);
      }
    }
  }
  void build() {
    ord.reserve(2 * V - 2);
    for(int i = 0; i < V; i++) {
      if(id[i] < 0) {
        dfs(i, -1, 0);
      }
    }
    vector<int> stvec(2 * V - 2);
    for(int i = 0; i < 2 * V - 2; i++) {
      stvec[i] = depth[ord[i]];
    }
    st.resize(stvec);
  }
  int solve(int u, int v) {
    return ord[st.query(min(id[u], id[v]), max(id[u], id[v]) + 1).second];
  }
  int dist(int u, int v) {
    int lca = solve(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
  }
};

vector<vector<ll>> T;
vector<ll> ans, tmp;

void dfs(int v, int p) {
  if(p == -1) {
    ans[v] += tmp[v];
  } else {
    ans[v] += ans[p] + tmp[v];
  }
  for(auto nv : T[v]) {
    if(nv == p)
      continue;
    dfs(nv, v);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n - 1), b(n - 1);
  rep(i, n - 1) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  LCA lca(n);
  T.assign(n, vector<ll>());
  ans.assign(n, 0);
  tmp.assign(n, 0);
  rep(i, n - 1) {
    lca.add_edge(a[i], b[i]);
    T[a[i]].push_back(b[i]);
    T[b[i]].push_back(a[i]);
  }
  lca.build();
  ll Q;
  cin >> Q;
  rep(i, Q) {
    ll t, e, x;
    cin >> t >> e >> x;
    e--;
    ll plus, minus;
    if(t == 1) {
      plus = a[e];
      minus = b[e];
    } else {
      plus = b[e];
      minus = a[e];
    }
    if(lca.depth[plus] < lca.depth[minus]) {
      // plusのほうが根に近い場合は根に+x minusに-xを足す
      tmp[0] += x;
      tmp[minus] -= x;
    } else {
      // plusのほうが根から遠い場合にはplusに+xを足す
      tmp[plus] += x;
    }
  }
  // dfsしながら累積和
  dfs(0, -1);
  rep(i, n) cout << ans[i] << endl;

  return 0;
}
