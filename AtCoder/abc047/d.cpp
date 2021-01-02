#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int N, T;
  cin >> N >> T;
  long long int minimum = 2000000000, max = 0, ans = 1;
  vector<long long int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    minimum = min(A[i], minimum);
    if(A[i] - minimum > max) {
      max = A[i] - minimum;
      ans = 1;
    } else if(A[i] - minimum == max) {
      ans++;
    }
  }
  cout << ans << endl;
}
