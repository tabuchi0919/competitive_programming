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
  vector<int> C(N), V(N);
  for(int i = 0; i < N; i++) {
    cin >> V[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> C[i];
  }
  for(int i = 0; i < N; i++) {
    if(V[i] > C[i])
      ans += V[i] - C[i];
  }
  cout << ans << endl;
}
