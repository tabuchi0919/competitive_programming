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

ll gcd(ll a, ll b) {
  if(a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  ll lcm = C / gcd(C, D) * D;
  cout << B - (B / C + B / D - B / lcm) -
              (A - 1 - ((A - 1) / C + (A - 1) / D - (A - 1) / lcm))
       << endl;
}
