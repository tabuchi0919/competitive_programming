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
  int ans = 1000000000;
  vector<int> a(5);
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
  sort(a.begin(), a.end());
  do {
    int tmp = 0;
    for(int i = 0; i < 4; i++) {
      tmp += ((a[i] + 9) / 10) * 10;
    }
    tmp += a[4];
    ans = min(ans, tmp);
  } while(std::next_permutation(a.begin(), a.end()));

  cout << ans << endl;
}
