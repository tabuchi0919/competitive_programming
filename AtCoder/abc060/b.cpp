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
  int A, B, C;
  cin >> A >> B >> C;
  string ans = "NO";
  for(int i = 1; i < B + 3; i++) {
    if(A * i % B == C) {
      ans = "YES";
    }
  }

  cout << ans << endl;
}
