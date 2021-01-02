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
  int N, init;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
    if(h[i] != 0)
      init = i;
  }
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      int height = abs(x[init] - i) + abs(y[init] - j) + h[init];
      bool flag = true;
      for(int k = 0; k < N; k++) {
        flag = flag && (h[k] == max(0, height - abs(x[k] - i) - abs(y[k] - j)));
      }
      if(flag)
        cout << i << " " << j << " " << height << endl;
    }
  }
}
