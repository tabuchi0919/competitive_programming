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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  int ans = 0;
  cin >> S;
  for(int i = 0; i < 4; i++) {
    if(S[i] == '+') {
      ans++;
    } else {
      ans--;
    }
  }
  cout << ans << endl;
}
