#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  long long int ans = 0;

  for(int i = 0; i < (1 << (n - 1)); i++) {
    long long int sum = 0;
    long long int tmp = s[0] - '0';
    for(int j = 0; j < n - 1; j++) {
      if(i & (1 << j)) {
        sum += tmp;
        tmp = 0;
      }
      tmp = tmp * 10 + s[j + 1] - '0';
    }
    sum += tmp;
    ans += sum;
  }
  cout << ans << endl;
}
