#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;
  vector<int> A(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  while(true) {
    for(int i = 0; i < N; i++) {
      if(A[i] % 2) {
        cout << ans << endl;
        return 0;
      } else {
        A[i] /= 2;
      }
    }
    ans++;
  }
}
