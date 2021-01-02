#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
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

int hoge(ll n, int cnt) {
  if(n % 2) {
    return cnt;
  } else {
    return hoge(n / 2, cnt + 1);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int D, N, ans = 1;
  cin >> D >> N;
  for(int i = 0; i < D; i++) {
    ans *= 100;
  }
  if(N == 100)
    N += 1;
  ans *= N;
  cout << ans << endl;
}
