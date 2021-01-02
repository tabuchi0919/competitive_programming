#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
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

// 交差判定セット（整数VER）
typedef complex<ll> C;
// 外積
ll cross(C a, C b) { return a.real() * b.imag() - a.imag() * b.real(); }
// 内積
ll dot(C a, C b) { return a.real() * b.real() + a.imag() * b.imag(); }
// a is in b and c ?
bool is_in(C a, C b, C c) {
  if(a == b)
    return true;
  if(a == c)
    return true;
  C v0 = b - a;
  C v1 = c - a;
  if(cross(v0, v1) != 0)
    return false; // 同一線上にない
  if(dot(v0, v1) < 0)
    return true; // 逆向きならin
  return false;
}
// ベクトル p0->p1, q0->q1
bool is_intersect(C p0, C p1, C q0, C q1) {

  {
    // 同じ点があるなら交差
    if(p0 == p1)
      return true;
    if(p0 == q0)
      return true;
    if(p0 == q1)
      return true;
    if(p1 == q0)
      return true;
    if(p1 == q1)
      return true;
    if(q0 == q1)
      return true;
  }

  bool is_parallel = false;
  {
    C v = p0 - p1;
    C w = q0 - q1;
    if(cross(v, w) == 0)
      is_parallel = true;
  }

  if(is_parallel) {
    // 包含・重なり・ギリギリ接触を交差とする

    if(is_in(p0, q0, q1))
      return true;
    if(is_in(p1, q0, q1))
      return true;

    if(is_in(q0, p0, p1))
      return true;
    if(is_in(q1, p0, p1))
      return true;

    return false;
  }

  // 以降、平行ではないとする

  // p側から見た交差チェック
  auto v0 = p1 - p0;
  auto v1 = q0 - p0;
  auto v2 = q1 - p0;
  if(cross(v0, v1) * cross(v0, v2) > 0) {
    return false;
  }
  // q側から見た交差チェック
  v0 = q1 - q0;
  v1 = p0 - q0;
  v2 = p1 - q0;
  if(cross(v0, v1) * cross(v0, v2) > 0) {
    return false;
  }

  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int ax, ay, bx, by, N;
  cin >> ax >> ay >> bx >> by >> N;
  vector<int> x(N), y(N);
  REP(i, N) cin >> x[i] >> y[i];
  int ans = 0;
  REP(i, N - 1) {
    if(is_intersect(C(ax, ay), C(bx, by), C(x[i], y[i]), C(x[i + 1], y[i + 1])))
      ans++;
  }
  if(is_intersect(C(ax, ay), C(bx, by), C(x[0], y[0]), C(x[N - 1], y[N - 1])))
    ans++;
  cout << 1 + ans / 2 << endl;
}
