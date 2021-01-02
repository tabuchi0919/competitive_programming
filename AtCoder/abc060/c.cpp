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
  long long N, T;
  cin >> N >> T;
  vector<long long> t(N);
  for(int i = 0; i < N; i++) {
    cin >> t[i];
  }
  long long ans = T;
  for(int i = 1; i < N; i++) {
    if(t[i] - t[i - 1] < T) {
      ans += t[i] - t[i - 1];
    } else {
      ans += T;
    }
  }

  cout << ans << endl;
}
