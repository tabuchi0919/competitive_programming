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
  long long H, W;
  long long s1, s2, s3, mi, ma, ans = 100000000;

  cin >> H >> W;
  for(int i = 1; i < H; i++) {
    s1 = W * i;
    s2 = (H - i) * (W / 2);
    s3 = (H - i) * (W - W / 2);
    mi = min(min(s1, s2), s3);
    ma = max(max(s1, s2), s3);
    ans = min(ma - mi, ans);
    s2 = ((H - i) / 2) * W;
    s3 = ((H - i) - (H - i) / 2) * W;
    mi = min(min(s1, s2), s3);
    ma = max(max(s1, s2), s3);
    ans = min(ma - mi, ans);
  }
  swap(H, W);

  for(int i = 1; i < H; i++) {
    s1 = W * i;
    s2 = (H - i) * (W / 2);
    s3 = (H - i) * (W - W / 2);
    mi = min(min(s1, s2), s3);
    ma = max(max(s1, s2), s3);
    ans = min(ma - mi, ans);
    s2 = ((H - i) / 2) * W;
    s3 = ((H - i) - (H - i) / 2) * W;
    mi = min(min(s1, s2), s3);
    ma = max(max(s1, s2), s3);
    ans = min(ma - mi, ans);
  }

  cout << ans << endl;
}
