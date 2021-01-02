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
  int n, k;
  string s;
  cin >> n >> k >> s;
  for(int i = 0; i < n; i++) {
    if(i == k - 1 && s[i] == 'A') {
      cout << 'a';
    } else if(i == k - 1 && s[i] == 'B') {
      cout << 'b';
    } else if(i == k - 1 && s[i] == 'C') {
      cout << 'c';
    } else {
      cout << s[i];
    }
  }
  cout << endl;
}
