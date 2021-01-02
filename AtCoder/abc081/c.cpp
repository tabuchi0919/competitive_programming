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
  vector<int> A(200001, 0);
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    A[tmp]++;
  }
  sort(A.rbegin(), A.rend());
  int ans = N;
  for(int i = 0; i < K; i++) {
    ans -= A[i];
  }
  cout << ans << endl;
}
