#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int x;
  cin >> x;
  string ans = "ABC";
  if(x >= 1200)
    ans = "ARC";
  cout << ans << endl;
}
