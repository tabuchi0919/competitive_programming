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
  vector<int> H(N);
  for(int i = 0; i < N; i++) {
    cin >> H[i];
  }
  for(int i = 0; i < N; i++) {
    bool flag = true;
    for(int j = 0; j < i; j++) {
      if(H[j] > H[i])
        flag = false;
    }
    if(flag)
      ans++;
  }
  cout << ans << endl;
}
