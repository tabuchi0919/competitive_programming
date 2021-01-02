#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, ans = 0;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int r, l;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
}
