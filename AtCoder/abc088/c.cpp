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
  int c[10];
  for(int i = 1; i < 10; i++)
    cin >> c[i];
  string ans = "No";
  if(((c[1] - c[2]) == (c[4] - c[5])) * ((c[1] - c[2]) == (c[7] - c[8])) *
     ((c[2] - c[3]) == (c[5] - c[6])) * ((c[2] - c[3]) == (c[8] - c[9])))
    ans = "Yes";

  cout << ans << endl;
}
