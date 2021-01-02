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
  int a, b, ans = 0;
  cin >> a >> b;
  if(a >= b) {
    ans += a;
    a--;
  } else {
    ans += b;
    b--;
  }
  if(a >= b) {
    ans += a;
    a--;
  } else {
    ans += b;
    b--;
  }
  cout << ans << endl;
}
