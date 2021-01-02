#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string a;
  cin >> a;
  int n = a.length();
  int cntp = 0, cntg = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    if(cntp == cntg) {
      if(a[i] == 'g') {
        cntg += 1;
      }
      if(a[i] == 'p') {
        cntg += 1;
        ans -= 1;
      }
    } else {
      if(a[i] == 'g') {
        cntp += 1;
        ans += 1;
      }
      if(a[i] == 'p') {
        cntp += 1;
      }
    }
  }

  cout << ans << endl;
}
