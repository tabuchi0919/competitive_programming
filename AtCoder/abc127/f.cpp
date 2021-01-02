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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int Q;
  ll left_sum = 0ll, right_sum = 0ll, sumb = 0ll;
  cin >> Q;
  priority_queue<ll> left;
  priority_queue<ll, vector<ll>, greater<ll>> right;
  REP(i, Q) {
    int q;
    ll a, b;
    cin >> q;
    if(q == 1) {
      cin >> a >> b;
      sumb += b;
      if(left.size() > right.size()) {
        int t = left.top();
        if(a >= t) {
          right.push(a);
          right_sum += a;
        } else {
          left.pop();
          left_sum -= t;
          left.push(a);
          left_sum += a;
          right.push(t);
          right_sum += t;
        }
      } else {
        if(left.empty()) {
          left.push(a), left_sum += a;
        } else {
          int t = right.top();
          if(a <= t) {
            left.push(a);
            left_sum += a;
          } else {
            right.pop();
            right_sum -= t;
            right.push(a);
            right_sum += a;
            left.push(t);
            left_sum += t;
          }
        }
      }
    } else {
      ll x = left.top();
      ll res = (x * (int)left.size() - left_sum) +
               (right_sum - x * (int)right.size()) + sumb;
      cout << x << " " << res << endl;
    }
  }
}
