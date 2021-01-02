#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int x;
  cin >> x;
  long long int ans = x / 11 * 2;
  if(x % 11 == 0) {

  } else if(x % 11 <= 6) {
    ans++;
  } else {
    ans += 2;
  }
  cout << ans << endl;
}
