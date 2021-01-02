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
  long long N, W, ans = 0, w1;
  cin >> N >> W;
  vector<long long> v1, v2, v3, v4;
  for(int i = 0; i < N; i++) {
    long long wtmp, vtmp;
    cin >> wtmp >> vtmp;
    if(i == 0) {
      w1 = wtmp;
      v1.push_back(vtmp);
    } else {
      if(wtmp == w1) {
        v1.push_back(vtmp);
      }
      if(wtmp == w1 + 1) {
        v2.push_back(vtmp);
      }
      if(wtmp == w1 + 2) {
        v3.push_back(vtmp);
      }
      if(wtmp == w1 + 3) {
        v4.push_back(vtmp);
      }
    }
  }
  sort(v1.rbegin(), v1.rend());
  sort(v2.rbegin(), v2.rend());
  sort(v3.rbegin(), v3.rend());
  sort(v4.rbegin(), v4.rend());
  for(int i = 0; i <= min(W / w1, (long long)v1.size()); i++) {
    for(int j = 0; j <= min((W - w1 * i) / (w1 + 1), (long long)v2.size());
        j++) {
      for(int k = 0; k <= min((W - w1 * i - (w1 + 1) * j) / (w1 + 2),
                              (long long)v3.size());
          k++) {
        long long tmp = 0;
        for(int l = 0; l < i; l++) {
          tmp += v1[l];
        }
        for(int l = 0; l < j; l++) {
          tmp += v2[l];
        }
        for(int l = 0; l < k; l++) {
          tmp += v3[l];
        }
        for(int l = 0;
            l < min((W - w1 * i - (w1 + 1) * j - (w1 + 2) * k) / (w1 + 3),
                    (long long)v4.size());
            l++) {
          tmp += v4[l];
        }
        ans = max(ans, tmp);
      }
    }
  }
  cout << ans << endl;
}
