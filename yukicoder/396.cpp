#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  X--;
  Y--;
  bool ans = false;
  if(X / M % 2 == Y / M % 2) {
    if(X % M == Y % M)
      ans = true;
  } else {
    if((X + Y) % M == M - 1)
      ans = true;
  }
  if(ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
