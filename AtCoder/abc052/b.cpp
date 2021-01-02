#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int n, ans = 0, tmp = 0;
  string s;
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'I') {
      tmp++;
    } else {
      tmp--;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
