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
  string S, ans = "TBD";
  cin >> S;
  if(S[6] <= '4' && S[5] == '0')
    ans = "Heisei";
  cout << ans << endl;
}
