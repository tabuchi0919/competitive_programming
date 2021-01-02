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
  int M, K;
  cin >> M >> K;
  if(M == 0) {
    if(K == 0) {
      cout << "0 0" << endl;
    } else {
      cout << -1 << endl;
    }
  } else if(M == 1) {
    if(K == 0) {
      cout << "0 1 1 0" << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    if(K < (1 << M)) {
      REP(i, (1 << M)) {
        if(i == K)
          continue;
        cout << i << ' ';
      }
      cout << K << ' ';
      REP(i, (1 << M)) {
        if((1 << M) - i - 1 == K)
          continue;
        cout << (1 << M) - i - 1 << ' ';
      }
      cout << K << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
