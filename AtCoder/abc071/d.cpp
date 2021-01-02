#include <algorithm>
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
const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  ll ans;
  string s, t;
  bool yoko;
  cin >> N >> s >> t;
  int i = 1;
  if(s[0] == t[0]) {
    yoko = false;
    ans = 3ll;
  } else {
    yoko = true;
    ans = 6ll;
    i++;
  }
  for(i; i < N; i++) {
    if(yoko) {
      if(s[i] == t[i]) {
        yoko = false;
      } else {
        ans *= 3;
        ans %= MOD;
        i++;
      }
    } else {
      if(s[i] == t[i]) {
        ans *= 2;
        ans %= MOD;
      } else {
        ans *= 2;
        ans %= MOD;
        yoko = true;
        i++;
      }
    }
  }
  cout << ans << endl;
}
