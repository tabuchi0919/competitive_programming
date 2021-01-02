#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int D, G, ans = 100000000;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for(int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }
  for(int bit = 0; bit < (1 << D); ++bit) {
    int sum = 0, cnt = 0;
    for(int i = 0; i < D; i++) {
      if(bit & (1 << i)) {
        sum += p[i] * 100 * (1 + i) + c[i];
        cnt += p[i];
      }
    }
    if(sum >= G) {
      ans = min(ans, cnt);
    } else {
      for(int i = D - 1; i >= 0; i--) {
        if(!(bit & (1 << i))) {
          if((p[i] - 1) * 100 * (1 + i) >= G - sum) {
            ans = min(ans, cnt + (G - sum + 100 * i) / (100 * (1 + i)));
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
