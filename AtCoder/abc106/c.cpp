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
  string s, ans;
  long long k, cnt = 0;
  cin >> s >> k;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] != '1')
      break;
    cnt++;
  }
  if(k <= cnt) {
    ans = '1';
  } else {
    ans = s[cnt];
  }
  cout << ans << endl;
}
