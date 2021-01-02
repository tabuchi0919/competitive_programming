#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> A(n);

  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end(), greater<int>());

  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      ans += A[i];
    } else {
      ans -= A[i];
    }
  }
  cout << ans << endl;
}
