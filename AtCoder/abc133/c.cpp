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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll L, R;
  cin >> L >> R;
  map<int, int> mp;
  for(ll i = L; i <= min(L + 2019 + 2018, R); i++) {
    mp[i % 2019]++;
  }
  int ans = INF;
  for(int i = 0; i < 2019; i++) {
    for(int j = 0; j < 2019; j++) {
      if(i == j) {
        if(mp[i] >= 2) {
          ans = min(ans, i * j % 2019);
        }
      } else {
        if(mp[j] > 0 && mp[i] > 0) {
          ans = min(ans, i * j % 2019);
        }
      }
    }
  }
  cout << ans << endl;
}
