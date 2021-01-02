#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long long N, ans;
  cin >> N;
  for(int i = 1; i <= sqrt(N); i++) {
    if(N % i != 0)
      continue;
    ans = log10(N / i) + 1;
  }
  cout << ans << endl;
}
