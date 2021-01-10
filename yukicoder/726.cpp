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

bool IsPrime(int n) {
  if(n < 2)
    return false;
  else if(n == 2)
    return true;
  else if(n % 2 == 0)
    return false;

  for(int i = 3; i * i <= n; i += 2) {
    if(n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int Y, X, cnt = 0;
  cin >> Y >> X;
  if(X == 2 || Y == 2) {
    cout << "Second" << endl;
  } else {
    while(true) {
      Y++;
      cnt++;
      if(IsPrime(Y))
        break;
    }
    while(true) {
      X++;
      cnt++;
      if(IsPrime(X))
        break;
    }
    cout << (cnt % 2 == 1 ? "First" : "Second") << endl;
  }
}
