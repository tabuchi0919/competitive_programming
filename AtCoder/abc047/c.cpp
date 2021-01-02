#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  for(int i = 0; i < S.size() - 1; i++) {
    if(S[i] != S[i + 1])
      ans++;
  }
  cout << ans << endl;
}
