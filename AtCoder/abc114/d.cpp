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
  int N, ans = 0;
  cin >> N;
  vector<int> num(101);
  for(int i = 2; i <= N; i++) {
    int tmp = i;
    for(int j = 2; j * j <= tmp; j++) {
      while(tmp % j == 0) {
        num[j]++;
        tmp /= j;
      }
    }
    if(tmp != 1)
      num[tmp]++;
  }

  for(int i = 2; i <= 100; i++) {
    if(num[i] >= 74)
      ans++;
  }

  for(int i = 2; i <= 100; i++) {
    for(int j = 2; j <= 100; j++) {
      if(j != i && num[i] >= 2 && num[j] >= 24)
        ans++;
    }
  }

  for(int i = 2; i <= 100; i++) {
    for(int j = 2; j <= 100; j++) {
      if(j != i && num[i] >= 4 && num[j] >= 14)
        ans++;
    }
  }

  for(int i = 2; i <= 100; i++) {
    for(int j = 2; j <= 100; j++) {
      for(int k = 2; k < j; k++) {
        if(j != i && i != k && k != j && num[i] >= 2 && num[j] >= 4 &&
           num[k] >= 4)
          ans++;
      }
    }
  }
  cout << ans << endl;
}
