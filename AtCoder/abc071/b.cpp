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
  string s;
  cin >> s;
  map<char, int> A;
  for(int i = 0; i < s.length(); i++) {
    A[s[i]]++;
  }
  bool flag = true;
  for(char t = 'a'; t <= 'z'; t++) {
    if(A[t] == 0) {
      cout << t << endl;
      flag = false;
      break;
    }
  }
  if(flag)
    cout << "None" << endl;
}
