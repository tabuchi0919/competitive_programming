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
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  int ans = 0;
  for(int i = 0; i < N; i++)
    cin >> A[i];
  for(int i = 0; i < N; i++)
    cin >> B[i];
  for(int i = 0; i < N; i++) {
    int tmp = 0;
    for(int j = 0; j <= i; j++) {
      tmp += A[j];
    }
    for(int j = i; j < N; j++) {
      tmp += B[j];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
