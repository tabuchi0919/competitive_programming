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
  int N = S.length();
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int tmp = 0;
    for(int j = i; j < N; j++) {
      if(S[j] == 'A' || S[j] == 'T' || S[j] == 'G' || S[j] == 'C') {
        tmp++;
      } else {
        break;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
