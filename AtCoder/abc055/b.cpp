#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int N, ans = 1;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    ans *= i;
    ans %= 1000000007;
  }
  cout << ans << endl;
}
