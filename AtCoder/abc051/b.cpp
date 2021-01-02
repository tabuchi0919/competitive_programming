#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int k, s;
  int ans = 0;
  cin >> k >> s;
  for(int i = 0; i <= k; i++) {
    for(int j = 0; j <= k; j++) {
      if(s - i - j >= 0 && s - i - j <= k) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
