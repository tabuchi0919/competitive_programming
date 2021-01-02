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
  int n, ans;
  cin >> n;
  if(n <= 104) {
    ans = 0;
  } else if(n <= 134) {
    ans = 1;
  } else if(n <= 164) {
    ans = 2;
  } else if(n <= 188) {
    ans = 3;
  } else if(n <= 194) {
    ans = 4;
  } else {
    ans = 5;
  }
  cout << ans << endl;
}
