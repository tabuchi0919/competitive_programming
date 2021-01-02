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
  int N, cntr = 0, cntl = 0;
  string S, ans = "";
  cin >> N >> S;
  for(int i = 0; i < N; i++) {
    if(S[i] == '(') {
      cntl++;
      ans.push_back('(');
    } else {
      cntr++;
      if(cntl < cntr) {
        cntl++;
        ans.insert(0, "(");
        ans.push_back(')');
      } else {
        ans.push_back(')');
      }
    }
  }
  for(int i = 0; i < cntl - cntr; i++) {
    ans.push_back(')');
  }
  cout << ans << endl;
}
