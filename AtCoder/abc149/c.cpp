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

vector<bool> IsPrime;

void sieve(int max) {
  if(max + 1 > IsPrime.size()) {
    IsPrime.resize(max + 1, true);
  }
  IsPrime[0] = false;
  IsPrime[1] = false;

  for(int i = 2; i * i <= max; ++i) {
    if(IsPrime[i]) {
      for(int j = 2; i * j <= max; ++j) {
        IsPrime[i * j] = false;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  sieve(200000);
  int N;
  cin >> N;
  while(true) {
    if(IsPrime[N]) {
      cout << N << endl;
      break;
    }
    N++;
  }
}
