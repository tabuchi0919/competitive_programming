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
  ll N;
  cin >> N;
  map<pair<ll, ll>, ll> mp;
  REP(i, N) {
    ll A, B;
    cin >> A >> B;
    if(A == 0 && B == 0) {
      mp[{0, 0}]++;
    } else {
      ll g = abs(gcd(A, B));
      A /= g;
      B /= g;
      if(A < 0) {
        A *= -1;
        B *= -1;
      }
      if(A == 0 && B < 0) {
        B *= -1;
      }
      mp[{A, B}]++;
    }
  }

  mint ans = 1;
  for(auto e : mp) {
    ll a = e.first.first, b = e.first.second;
    if(b > 0) {
      ans *= (mint(2).pow(e.second) + mint(2).pow(mp[{b, -a}]) - 1);
    } else {
      if(mp.count({-b, a}) == 0) {
        ans *= (mint(2).pow(e.second));
      }
    }
  }

  cout << ans + mp[{0, 0}] - 1 << endl;
}
