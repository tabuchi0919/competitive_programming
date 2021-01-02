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
  int N, T, A, mi = 10000000, ans;
  cin >> N >> T >> A;
  vector<int> H(N);
  for(int i = 0; i < N; i++)
    cin >> H[i];
  for(int i = 0; i < N; i++) {
    mi = min(mi, abs(1000 * A - (T * 1000 - H[i] * 6)));
    if(mi == abs(1000 * A - (T * 1000 - H[i] * 6)))
      ans = i + 1;
  }
  cout << ans << endl;
}
