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
  int n;
  cin >> n;
  long long a[100100];
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long count1 = 0;
  long long su1 = 0;
  for(int j = 0; j < n; ++j) {
    su1 += a[j];
    if(j % 2 == 0 && su1 <= 0) {
      count1 += -su1 + 1;
      su1 = 1;
    } else if(j % 2 == 1 && su1 >= 0) {
      count1 += su1 + 1;
      su1 = -1;
    }
  }
  long long count2 = 0;
  long long su2 = 0;
  for(int j = 0; j < n; ++j) {
    su2 += a[j];
    if(j % 2 == 0 && su2 >= 0) {
      count2 += su2 + 1;
      su2 = -1;
    } else if(j % 2 == 1 && su2 <= 0) {
      count2 += -su2 + 1;
      su2 = 1;
    }
  }
  cout << min(count1, count2) << endl;
}
