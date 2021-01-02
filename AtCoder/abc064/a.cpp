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
  int r, g, b;
  cin >> r >> g >> b;
  string ans = "NO";
  if((10 * g + b) % 4 == 0)
    ans = "YES";
  cout << ans << endl;
}
