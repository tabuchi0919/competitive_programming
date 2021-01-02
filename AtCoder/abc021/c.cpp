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

using namespace std;
typedef long long ll;

template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

template <int Modulo = MOD> struct Mint {
  ll val;
  constexpr Mint(ll v = 0) noexcept : val(v % Modulo) {
    if(val < 0)
      val += Modulo;
  }

  constexpr Mint &operator+=(const Mint &r) noexcept {
    val += r.val;
    if(val >= Modulo)
      val -= Modulo;
    return *this;
  }
  constexpr Mint &operator-=(const Mint &r) noexcept {
    val -= r.val;
    if(val < 0)
      val += Modulo;
    return *this;
  }
  constexpr Mint &operator*=(const Mint &r) noexcept {
    val = val * r.val % Modulo;
    return *this;
  }
  constexpr Mint &operator/=(const Mint &r) noexcept {
    ll a = r.val, b = Modulo, u = 1, v = 0;
    while(b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    val = val * u % Modulo;
    if(val < 0)
      val += Modulo;
    return *this;
  }

  constexpr Mint operator+(const Mint &r) const noexcept {
    return Mint(*this) += r;
  }
  constexpr Mint operator-(const Mint &r) const noexcept {
    return Mint(*this) -= r;
  }
  constexpr Mint operator*(const Mint &r) const noexcept {
    return Mint(*this) *= r;
  }
  constexpr Mint operator/(const Mint &r) const noexcept {
    return Mint(*this) /= r;
  }

  constexpr int getmod() { return Modulo; }
  constexpr Mint operator-() const noexcept { return val ? Modulo - val : 0; }

  constexpr bool operator==(const Mint &r) const noexcept {
    return val == r.val;
  }
  constexpr bool operator!=(const Mint &r) const noexcept {
    return val != r.val;
  }

  friend ostream &operator<<(ostream &os, const Mint<Modulo> &x) noexcept {
    return os << x.val;
  }
  friend istream &operator>>(istream &is, Mint<Modulo> &x) noexcept {
    ll tmp;
    is >> tmp;
    x = Mint(tmp);
    return is;
  }

  constexpr Mint pow(ll n) noexcept {
    Mint res{1}, tmp{val};
    while(n > 0) {
      if(n & 1)
        res *= tmp;
      tmp *= tmp;
      n >>= 1;
    }
    return res;
  }
};
using mint = Mint<>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, a, b, M;
  cin >> N >> a >> b >> M;
  a--;
  b--;
  vector<vector<int>> G(N);
  REP(i, M) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  queue<int> q;
  vector<mint> dp(N, mint(0));
  vector<int> cnt(N, -1);
  dp[a] = 1;
  cnt[a] = 0;
  q.push(a);
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    for(int next : G[now]) {
      if(cnt[next] == -1) {
        cnt[next] = cnt[now] + 1;
        dp[next] += dp[now];
        q.push(next);
      } else if(cnt[next] == cnt[now] + 1) {
        dp[next] += dp[now];
      }
    }
  }
  cout << dp[b] << endl;
}
