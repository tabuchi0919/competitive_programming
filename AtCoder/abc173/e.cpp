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
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  if(N == K) {
    mint ans = 1;
    REP(i, N) ans *= A[i];
    cout << ans << endl;
  } else if(K % 2 == 1 && *max_element(ALL(A)) < 0) {
    sort(rALL(A));
    mint ans = 1;
    REP(i, K) ans *= A[i];
    cout << ans << endl;
  } else {
    vector<ll> hifu, fu, abss(N);
    mint ans = 1;
    sort(ALL(A),
         [](auto const &lhs, auto const &rhs) { return abs(lhs) > abs(rhs); });
    bool positive = true;
    REP(i, K) {
      ans *= A[i];
      if(A[i] < 0)
        positive = !positive;
    }
    if(!positive) {
      // 次の正の値(ないかも)、次の負の値(ないかも)を調べる
      // 最後の正の値(ないかも)、最後の負の値(ある)も調べる
      ll next_positive = INFLL, next_negative = INFLL;
      ll last_positive = INFLL, last_negative;
      FOR(i, K, N) {
        if(A[i] >= 0) {
          next_positive = A[i];
          break;
        }
      }
      FOR(i, K, N) {
        if(A[i] < 0) {
          next_negative = A[i];
          break;
        }
      }
      REP(j, K) {
        int i = K - j - 1;
        if(A[i] >= 0) {
          last_positive = A[i];
          break;
        }
      }
      REP(j, K) {
        int i = K - j - 1;
        if(A[i] < 0) {
          last_negative = A[i];
          break;
        }
      }
      if(next_positive == INFLL) {
        ans *= next_negative;
        ans /= last_positive;
      } else if(next_negative == INFLL || last_positive == INFLL) {
        ans *= next_positive;
        ans /= last_negative;
      } else {
        // last_negativeで割って、next_positiveをかける
        // vs
        // last_positiveで割って、next_negativeをかける
        if(next_positive * last_positive > next_negative * last_negative) {
          ans *= next_positive;
          ans /= last_negative;
        } else {
          ans *= next_negative;
          ans /= last_positive;
        }
      }
    }
    cout << ans << endl;
  }
}
