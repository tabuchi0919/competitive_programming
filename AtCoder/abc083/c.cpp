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
  long long X, Y;
  cin >> X >> Y;
  long long ans = 0LL;
  while(X <= Y) {
    X *= 2;
    ans++;
  }
  cout << ans << endl;
}
