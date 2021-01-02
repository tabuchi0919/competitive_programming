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
  string S, ans = "yes";
  cin >> S;
  vector<int> s(26);
  int i = 0;
  for(char t = 'a'; t <= 'z'; t++) {
    if(S.rfind(t) != S.find(t)) {
      ans = "no";
    }
  }
  cout << ans << endl;
}
