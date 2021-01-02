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
  string S;
  cin >> S;
  int ans = 1000000, N = S.length();
  int tmp = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 1 && S[i] == '1') {
      tmp++;
    }
    if(i % 2 == 0 && S[i] == '0') {
      tmp++;
    }
  }
  ans = min(ans, tmp);

  tmp = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 1 && S[i] == '0') {
      tmp++;
    }
    if(i % 2 == 0 && S[i] == '1') {
      tmp++;
    }
  }
  ans = min(ans, tmp);

  cout << ans << endl;
}
