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
  int N, ans = 0;
  cin >> N;
  vector<int> s(N);
  for(int i = 0; i < N; i++) {
    cin >> s[i];
    ans += s[i];
  }
  sort(s.begin(), s.end());
  if(ans % 10 == 0) {
    for(int i = 0; i < N; i++) {
      if(s[i] % 10 == 0) {
        continue;
      } else {
        ans -= s[i];
        break;
      }
    }
  }

  if(ans % 10 == 0)
    ans = 0;

  cout << ans << endl;
}
