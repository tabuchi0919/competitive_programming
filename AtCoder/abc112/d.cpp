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
  int N, M, ans;
  cin >> N >> M;
  for(int i = 1; i * i <= M; i++) {
    if(M % i == 0) {
      int j = M / i;
      if(i <= M / N) {
        ans = max(ans, i);
      }
      if(j <= M / N) {
        ans = max(ans, j);
      }
    }
  }

  cout << ans << endl;
}
