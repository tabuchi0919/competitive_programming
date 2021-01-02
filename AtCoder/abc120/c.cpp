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
  int N, ans = 0, cnt = 0;
  string S;
  cin >> S;
  N = S.length();
  for(int i = 0; i < N; i++) {
    if(S[i] == '0') {
      cnt++;
    }
  }
  cout << min(cnt, N - cnt) * 2 << endl;
}
