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
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "No";
  if(a <= c && c <= b) {
    ans = "Yes";
  }
  cout << ans << endl;
}
