#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long int ans = 1;
  map<int, int> mp;
  for(int i = 2; i <= n; i++) {
    int tmp = i;
    for(int j = 2; j <= i; j++) {
      while(tmp % j == 0) {
        tmp /= j;
        mp[j]++;
      }
    }
  }
  for(auto x : mp) {
    ans = ans * (x.second + 1);
    ans = ans % (1000000007);
  }
  cout << ans << endl;
}
