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
  int x, y;
  cin >> x >> y;
  string ans = "No";
  int s[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  if(s[x] == s[y])
    ans = "Yes";
  cout << ans << endl;
}
