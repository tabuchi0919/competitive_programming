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
  int ans = 100000000, N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> l(N), D(N);
  for(int i = 0; i < N; i++) {
    cin >> l[i];
  }
  for(int mask = 0; mask < pow(4, N); mask++) {
    int tmp = mask;
    int al = 0, bl = 0, cl = 0;
    int an = 0, bn = 0, cn = 0;
    for(int pos = 0; pos < N; pos++) {
      if(tmp % 4 == 1) {
        al += l[pos];
        an++;
      }
      if(tmp % 4 == 2) {
        bl += l[pos];
        bn++;
      }
      if(tmp % 4 == 3) {
        cl += l[pos];
        cn++;
      }
      tmp /= 4;
    }
    if(an * bn * cn != 0) {
      int tmp2 =
          abs(A - al) + abs(B - bl) + abs(C - cl) + (an + bn + cn - 3) * 10;
      ans = min(ans, tmp2);
    }
  }
  cout << ans << endl;
}
