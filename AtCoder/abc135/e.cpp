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

struct r2 {
  int x, y;
};
vector<r2> ans;

void move(int x, int y) {
  nowx += x;
  nowy += y;
  ans.push_back({nowx, nowy});
}

int k, x, y, nowx = 0, nowy = 0;

int main() {
  cin >> k >> x >> y;

  if(!(k & 1) && ((x + y) & 1)) {
    cout << -1 << endl;
    return 0;
  }
  if(abs(x) + abs(y) == k) {
    cout << 1 << endl << x << " " << y << endl;
    return 0;
  }

  int X = abs(x), Y = abs(y);
  if(X > Y)
    swap(X, Y);

  int sousai = -1;
  for(int j = k * 2; sousai < 0; j += k)
    if((j - (X + Y)) % 2 == 0)
      sousai = (j - (X + Y)) / 2;

  if(sousai) {
    while(sousai >= k) {
      move(0, -k);
      sousai -= k;
    }
    move(-sousai, k - sousai);
  }

  while(nowx + k <= X)
    move(k, 0);
  while(nowy + k <= Y)
    move(0, k);
  if(nowx != X || nowy != Y)
    ans.push_back({X, Y});

  cout << ans.size() << endl;

  for(auto p : ans) {
    int ansx = p.x, ansy = p.y;
    if(abs(x) > abs(y))
      swap(ansx, ansy);
    if(x < 0)
      ansx *= -1;
    if(y < 0)
      ansy *= -1;
    cout << ansx << " " << ansy << endl;
  }
}
