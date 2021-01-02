#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {

  cin.tie(0);
  ios::sync_with_stdio(false);
  string S, T;
  cin >> S >> T;
  bool flag = true;
  map<char, char> ma1, ma2;
  for(int i = 0; i < S.size(); i++) {
    if(ma1.count(S[i]) && ma1[S[i]] != T[i])
      flag = false;
    if(ma2.count(T[i]) && ma2[T[i]] != S[i])
      flag = false;
    ma1[S[i]] = T[i];
    ma2[T[i]] = S[i];
  }
  if(flag) {
    puts("Yes");
  } else {
    puts("No");
  }
}
